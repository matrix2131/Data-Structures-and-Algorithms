/*
You are given the root of a binary tree where each node has a value 0 or 1.  
Each root-to-leaf path represents a binary number starting with the most significant bit.  

For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers. The answer is guaranteed to fit in a 32-bits integer.
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

int ans = 0;
void help(TreeNode* root, vector<int> v) {
        if(root == NULL)
            return;
        v.push_back(root->val);
        help(root->left, v);
        help(root->right, v);
        if(!root->left && !root->right)
        {
            int sum = 0;
            int r = v.size();
            for(int i = 0; i<v.size(); i++)
            {
                sum += v[i]*pow(2,r-1);
                r--;
            }
            ans += sum;
        }
        v.pop_back();
        
    }
    
int sumRootToLeaf(TreeNode* root)
    {
        vector<int> v;
        help(root,v);
        return ans;
    }


int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    cout<<sumRootToLeaf(root)<<endl;
}
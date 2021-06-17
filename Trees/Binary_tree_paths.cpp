/*
Given the root of a binary tree, return all root-to-leaf paths in any order.

Time Complexity -> O(n)
Space Complexity -> )(h)
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

vector<string> ans;
    
    void helper(TreeNode *root, string s)
    {
        if(root == NULL)
            return;
        if(!root->right && !root->left)
        {
            s += to_string(root->val);
            ans.push_back(s);
            return;
        }
        
        s += to_string(root->val);
        s += "->";
        helper(root->left, s);
        helper(root->right, s);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string s = "";
        helper(root,s);
        return ans;
    }
    
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    vector<string> a = binaryTreePaths(root);
    for(int i = 0; i<a.size(); i++)
    {
        cout<<a[i]<<endl;
    }
}
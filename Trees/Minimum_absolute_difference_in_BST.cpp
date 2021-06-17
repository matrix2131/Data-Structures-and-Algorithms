/*
Given the root of a Binary Search Tree (BST), return the minimum 
absolute difference between the values of any two different nodes in the tree.
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

vector<int> n;
    
    void preorder(TreeNode* root)
    {
        if(root == NULL)
            return;
    
        preorder(root->left);
        n.push_back(root->val);
        preorder(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        
        int m = INT_MAX;
        preorder(root);
        for(int i = 0; i<n.size()-1; i++)
        {
            m = min(m,abs(n[i] - n[i+1]));                
        }
        return m;
    }
    
int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    
    cout<<getMinimumDifference(root);
}
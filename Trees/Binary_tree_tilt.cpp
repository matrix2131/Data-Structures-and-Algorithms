/*
Given the root of a binary tree, return the sum of every tree node's tilt.

The tilt of a tree node is the absolute difference between the sum of all 
left subtree node values and all right subtree node values. If a node does 
not have a left child, then the sum of the left subtree node values is treated 
as 0. The rule is similar if there the node does not have a right child.

 
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


int helper(TreeNode* root, int& s)
    {
        if(root == NULL)
            return 0;
        
        int left_sum = 0, right_sum = 0;
        left_sum = helper(root->left,s);
        right_sum = helper(root->right,s);
        
        s += abs(left_sum - right_sum);
        
        return(root->val + left_sum + right_sum);
    }
    
    
    int findTilt(TreeNode* root) {
        int sum = 0;
        helper(root, sum);
        return sum;
    }
    
    
int main()
{
    TreeNode *root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(9);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(5);
    root1->right->right = new TreeNode(7);
    
    int s=0;
    cout<<findTilt(root1);
}


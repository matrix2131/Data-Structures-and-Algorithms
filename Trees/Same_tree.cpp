/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
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

 bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans;
        if(!p && q)
            return false;
        if(!q && p)
            return false;
        if(!p && !q)
            return true;
        if(p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right, q->right))
            return true;
        return false;
    }
    
int main()
{
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    // root1->left->left = new Node(5);
    
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    // root2->left->right = new Node(4);
    // root2->right->right = new Node(7);
    
    cout<<isSameTree(root1,root2);
}
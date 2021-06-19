/*

Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two 
nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to 
be a descendant of itself).”
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

TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root->val >= p->val && root->val <= q->val)
            return root;
        
        if(root->val < p->val)
            return helper(root->right, p,q);
        
        if(root->val > q->val)
            return helper(root->left,p,q);
        
        return root;
    }
        
        
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* r;
       if(p->val > q->val)
       {
           r = q;
           q = p;
           p = r;
       }
        r = helper(root,p,q);
        return r;
    }
    
int main()
{
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    
    TreeNode* p = new TreeNode(2);
    TreeNode* q = new TreeNode(8);
    TreeNode* p2 = new TreeNode(2);
    TreeNode* q2 = new TreeNode(4);
    TreeNode* ans1;
    TreeNode* ans2;
    
    ans1 = lowestCommonAncestor(root,p,q);
    cout<<"LCA : "<<ans1->val<<endl;
    
    ans2 = lowestCommonAncestor(root,p2,q2);
    cout<<"LCA : "<<ans2->val<<endl;
    
    
}
/*
Given the root of a Binary Search Tree and a target number k, return true if there
 exist two elements in the BST such that their sum is equal to the given target.
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

// METHOD 1 - USING RECURSION
TreeNode *head;
    bool search(TreeNode* root, int key)
    {
        if(root == NULL)
            return false;
        if(root->val == key)
            return true;
        if(root->val < key)
            return search(root->right, key);
        return search(root->left,key);
    }
    
    bool fun(TreeNode* root, int k)
    {
        if(root == NULL)
            return false;
        
        if(root->val != k - root->val)
        {
            if(search(head, k-root->val))
                return true;
        }
        return fun(root->right, k) || fun(root->left,k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        head = root;
        return fun(root,k);
    }

// METHOD 2 - USING INORDER TRAVERSAL TO STORE THE VALues of nodes in ascending order.
vector<int> a;
    void inorder(TreeNode* root, vector<int>& a)
    {
        if(root == NULL)
            return;
        inorder(root->left,a);
        a.push_back(root->val);
        inorder(root->right, a);
    }
    
    bool findTarget2(TreeNode* root, int k) {
        inorder(root,a);
        int l = 0, h = a.size()-1;
        
        while(l<h)
        {
            if(a[l] + a[h] == k)
                return true;
            else if(a[l] + a[h] > k)
                h--;
            else
                l++;
        }
        return false;
    }

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    // root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
   
   int key = 9;
   cout<<findTarget(root,key)<<endl;
   cout<<findTarget2(root,key)<<endl;
   
}
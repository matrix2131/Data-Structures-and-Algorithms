/*
You are given two binary trees root1 and root2.

Imagine that when you put one of them to cover the other, 
some nodes of the two trees are overlapped while the others are not. 
You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, 
then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used 
as the node of the new tree.

Return the merged tree.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* mergeTrees(Node* root1, Node* root2) {
        
        if(!root1)
            return root2;
        if(!root2)
            return root1;
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left , root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
}

void inorder(Node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(3);
    root1->right = new Node(2);
    root1->left->left = new Node(5);
    
    Node *root2 = new Node(2);
    root2->left = new Node(1);
    root2->right = new Node(3);
    root2->left->right = new Node(4);
    root2->right->right = new Node(7);
    
    Node *ans;
    ans = mergeTrees(root1, root2);
    inorder(ans);
}
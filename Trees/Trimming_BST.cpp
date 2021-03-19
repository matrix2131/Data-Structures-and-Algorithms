#include <bits/stdc++.h>
using namespace std;
/* structure of a tree node */
class TreeNode
{
    public:
    
    int data;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int num)
    {
        data = num;
        left = right = NULL;
    }
};
/* function to trim the BST */
TreeNode *trimBST(TreeNode *root,int L,int R)
{
    if (root == NULL) 
    return root;
    
    root->left = trimBST(root->left,L,R);
    root->right = trimBST(root->right,L,R);
    
    if(root->data >= L && root->data <= R)
        return root;
    if(root->data < L)
        return root->right;
    if(root->data > R)
        return root->left;
    
    return root;
}
/* function to perform inorder traversal of the BST */
static void inorder(TreeNode *root)
{
    if(root == NULL)
    return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main() 
{
    /* construct the BST */
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    
    cout<<"Inorder Traversal Without Trimming: ";
    inorder(root);
    
    /* define the upper and lower bound of the 
    ranges into which the BST needs to be trimmed */
    int L = 2;
    int R = 6;
    
    root = trimBST(root,L,R);
    cout<<endl;
    
    cout<<"Inorder Traversal After Trimming: ";
    inorder(root);
  return 0;
}

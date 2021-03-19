#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *right;
    node *left;
    node(int val): data(val), right(NULL), left(NULL) {}
};

int GreaterTree(node *node, int sum)
{
    if(node == NULL)
        return sum;
    sum = node->data + GreaterTree(node->right, sum);
    node->data = sum;
    sum = GreaterTree(node->left, sum);
    return sum;
        
}
    
    
node* convertBST(node* root) {
     if(root == NULL)
         return root;
    
    GreaterTree(root,0);
        return root;
}

void Inorder(node *root)
{
    if(root == NULL)
        return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}


int main()
{
    struct node *root = new node(11);
    root->left = new node(2);
    root->right = new node(29);
    root->left->left = new node(1);
    root->left->right = new node(7);
    root->right->left = new node(15);
    root->right->right = new node(40);
    root->right->right->left = new node(35);
 
    cout << "Inorder Traversal of given tree\n";
    Inorder(root);
 
    convertBST(root);
 
    cout << "\n\nInorder Traversal of transformed tree\n";
    Inorder(root);
 
    return 0;
}

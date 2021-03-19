#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    
    node(int key)
    {
        data = key;
        left = NULL;
        right = NULL;
    }
};

bool ContinousTree(node* root)
{
    if(root == NULL)
        return true;
    if(root->left == NULL && root->right == NULL)
        return true;
   
   if(root->left == NULL)
   {
       return ((abs(root->data = root->right->data) == 1) && ContinousTree(root->right));
   }
   
   if(root->right == NULL)
   {
       return ((abs(root->data = root->left->data) == 1) && ContinousTree(root->left));
   }
   
   return ((abs(root->data = root->right->data) == 1) &&  (abs(root->data = root->left->data) == 1) && ContinousTree(root->left) && ContinousTree(root->right));
}

int main()
{
    node* root = new node(3);
    root->left = new node(3);
    root->right = new node(2);
    root->left->left = new node(1);
    ContinousTree(root) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
}

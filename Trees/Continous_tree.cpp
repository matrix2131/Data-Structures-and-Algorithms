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

void ContinousTree(node* root)
{
    if(root == NULL)
        cout<<"Tree is empty!";
    if(root->left == NULL && root->right == NULL)
    {
        cout<<"Yes"<<endl;
    }
        
    queue<node*> q;
    q.push(root);
    
    node* temp;
    
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        
        if(temp->left)
        {
            if(abs(temp->left->data - temp->data) == 1)
                q.push(temp->left);
            else
            {
                cout<<"No"<<endl;
                return;
            }
        }
        
        if(temp->right)
        {
            if(abs(temp->data - temp->right->data) == 1)
                q.push(temp->right);
            else
            {
                cout<<"No"<<endl;
                return;
            }
        }
    }
    cout<<"Yes"<<endl;
}

int main()
{
    node* root = new node(3);
    root->left = new node(3);
    root->right = new node(2);
    root->left->left = new node(1);
    ContinousTree(root);
}

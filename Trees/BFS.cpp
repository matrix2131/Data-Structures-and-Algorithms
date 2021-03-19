#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* createNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void BFS(Node *root)
{
    if(root == NULL)
    {
        cout<<"Empty Tree"<<endl;
    }
    
    queue<Node*> q;
    q.push(root);
    Node *temp;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        
        if(temp->left)
        {
            q.push(temp->left);
        }
        
        if(temp->right)
        {
            q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->left->left = createNode(4);
    root->right = createNode(3);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->left->left->left = createNode(7);
    BFS(root);
}

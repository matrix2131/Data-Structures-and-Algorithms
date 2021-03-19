#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *InsertNode(int data, Node* root)
{
    if(root == NULL)
    {
        root = createNode(data);
        return root;
    }
    
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        
        if(temp->left != NULL)
            q.push(temp->left);
        else
        {
            temp->left = createNode(data);
            return root;
        }
        
        if(temp->right != NULL)
            q.push(temp->right);
        else
        {
            temp->right = createNode(data);
            return root;
        }
    }
}

void inorder(Node* temp)
{
    if(temp == NULL)
        return;
    
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
}

int main()
{
    Node *root = new Node();
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(3);
    
    cout<<"Inorder Traversal before insertion: ";
    inorder(root);
    cout<<endl;
    
    int key = 12;
    InsertNode(key,root);
    
    cout<<"Inorder Traversal after insertion: ";
    inorder(root);
    cout<<endl;
}

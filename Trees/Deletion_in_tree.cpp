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

void deleteDeepest(Node* root, Node* deepest)
{
    queue<Node*> q;
    q.push(root);
    
    Node* temp;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        
        if(temp == deepest)
        {
            temp = NULL;
            delete(temp);
            return;
        }
        
        if(temp->left)
        {
            if(temp->left == deepest)
            {
                temp->left = NULL;
                delete(temp->left);
                return;
            }
            else
                q.push(temp->left);
        }
        
        if(temp->right)
        {
            if(temp->right == deepest)
            {
                temp->right = NULL;
                delete(temp->right);
                return;
            }
            else
                q.push(temp->right);
        }
    }

}

Node* deletion(Node *root, int key)
{
    if(root == NULL)
        return NULL;
    if(root->left == NULL && root->right == NULL)
    {
        if(root->data == key)
            return NULL;
        else
            return root;
    }
    
    queue<Node*> q;
    q.push(root);
    Node *temp;
    Node *key_node = NULL;
    
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        
        if(temp->data == key)
        {
            key_node = temp;
        }
        
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
        if(key_node != NULL)
        {
            int x = temp->data;   // This is the value of deepest node in tree.
            deleteDeepest(root, temp);
            key_node->data = x;
        }
        return root;
}

void inorder(Node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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
    
    int key = 2;
    deletion(root ,key);
    inorder(root);
}

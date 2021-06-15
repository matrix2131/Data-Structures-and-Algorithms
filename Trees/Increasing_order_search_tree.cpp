/*
Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node
 in the tree is now the root of the tree, and every node has no left child and only one right child.

*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* ans = new Node(0);
Node* p = ans;
void solveInorder(Node *root)
{
    if(root == NULL)
        return;
    solveInorder(root->left);
    if(root)
    {
        root->left = NULL;
        p->right = root;
        p = p->right;
    }
    solveInorder(root->right);
}

Node* increasingBST(Node* root) {
    solveInorder(root);
    return ans->right;
}

void inorder(Node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void LevelOrderTraversal(Node* root) {
        vector<int> ans;
        
        if(root == NULL)
        {
            cout<<"No tree"<<endl;
        }
    
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int count = q.size();
            
            while(count > 0)
            {
                Node *temp = q.front();
                cout<<temp->val<<" ";
                q.pop();
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                count--;
            }
        }
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);
    root->right->right = new Node(8);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(9);
    
    Node *out;
    out = increasingBST(root);
    LevelOrderTraversal(out);
    cout<<endl;
    inorder(out);
}
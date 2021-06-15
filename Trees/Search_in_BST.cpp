/*
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. 
If such a node does not exist, return null.
*/


#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* search(Node *root, int val)
    {
        if(root == NULL)
            return root;
        if(root->val == val)
            return root;
        
        if(root->val < val)
            return search(root->right,val);
        else
            return search(root->left, val);
    }
    
Node* searchBST(Node* root, int val) {
        Node* ans = search(root,val);
        return ans;
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
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    // root->left->left->left = new Node(1);
    // root->right->right = new Node(8);
    // root->right->right->left = new Node(7);
    // root->right->right->right = new Node(9);
    int key = 2;
    
    Node *ans;
    ans = searchBST(root,key);
    LevelOrderTraversal(ans);
    cout<<endl;
}
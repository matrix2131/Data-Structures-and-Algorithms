#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    
    node(int value) : data(value), left(NULL), right(NULL) {}
    
};

void LevelOrderTraversal(node* root) {
        vector<int> ans;
        
        if(root == NULL)
        {
            cout<<"No tree"<<endl;
        }
    
        queue<node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int count = q.size();
            
            while(count > 0)
            {
                node *temp = q.front();
                cout<<temp->data<<" ";
                q.pop();
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                count--;
            }
            cout<<endl;
        }
}


int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->left = new node(5);
    root->left->left->right = new node(6);
    root->left->left->right->left = new node(7);
    LevelOrderTraversal(root);
    
}

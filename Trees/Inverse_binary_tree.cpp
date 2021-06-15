#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

/*  METHOD I

TreeNode* invertTree(TreeNode* root) {
    if(root==NULL){
        return NULL;
    }
    TreeNode* temp;
    temp=root->left;
    root->left=root->right;
    root->right=temp;
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}
*/

// METHOD 2
TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        TreeNode *l = invertTree(root->left);
        TreeNode *r = invertTree(root->right);
        
        root->left = r;
        root->right = l;
        
        return root;
    }
/*
    METHOD 3 --> ITERATIVE APPROACH
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
       
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            
            swap(curr->left, curr->right);
            
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
        return root;
    }
*/

void LevelOrderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(root == NULL)
        {
            cout<<"No tree"<<endl;
        }
    
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int count = q.size();
            
            while(count > 0)
            {
                TreeNode *temp = q.front();
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
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
   
   invertTree(root);
   LevelOrderTraversal(root);
   
}
/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of 
every node never differs by more than one.
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

TreeNode* help(int start, int end, vector<int> &n)
    {
        if(start > end)
            return NULL;
        int mid = (start+end)/2;
        TreeNode *root = new TreeNode(n[mid]);
        root->left = help(start, mid-1, n);
        root->right = help(mid+1, end, n);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return help(0,nums.size()-1,nums);    
    }
    
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
    vector<int> nums = {-10,-3,0,5,9};
    TreeNode *root = sortedArrayToBST(nums);
    LevelOrderTraversal(root);
   
}
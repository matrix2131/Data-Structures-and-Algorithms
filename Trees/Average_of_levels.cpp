/*
Given the root of a binary tree, return the average value of the nodes on each level in the form of an array.
 Answers within 10-5 of the actual answer will be accepted.
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

vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root == NULL) 
        {
            ans.push_back(0);
            return ans;
        }
            
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            double sum = 0;
            double n = q.size();
            int count = q.size();
            while(count > 0)
            {
                TreeNode *temp = q.front();
                sum += temp->val;
                q.pop();
                
                if(temp->left)
                    q.push(temp->left);
                    
                if(temp->right)
                    q.push(temp->right); 
                count--;
            }
            ans.push_back(sum/n);            
        }
        return ans;
    }

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
   
   vector<double> ans;
   ans = averageOfLevels(root);
   for(int i = 0; i<ans.size(); i++)
    cout<<fixed<<setprecision(5)<<ans[i]<<" ";
   
}
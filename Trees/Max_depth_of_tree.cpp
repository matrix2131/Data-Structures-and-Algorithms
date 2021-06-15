#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

// Method 1
int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        return 1+ max(maxDepth(root->left), maxDepth(root->right));
    }

// Method 2
int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        else
        {
            int ldepth = maxDepth(root->left);
            int rdepth = maxDepth(root->right);
            
            if(rdepth > ldepth)
                return rdepth+1;
            return ldepth+1;
            
            
        }
}


int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    cout<<"Max depth of tree: "<<maxDepth(root)<<endl;
}
/*
Given the root of a binary tree, construct a string consists of parenthesis 
and integers from a binary tree with the preorder traversing way, and return it.

Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship 
between the string and the original binary tree.
*/


/*
    Time Complexity --> O(n)
    Space complexity --> O(h)   h = height of tree
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

string s = "";
    
    string tree2str(TreeNode* root) {
        s += to_string(root->val);
        
        if(root->left)
        {
            s += '(';
            tree2str(root->left);
            s+= ')';
            
            if(root->right)
            {
                s +=  '(';
                tree2str(root->right);
                s+= ')';
            }
        }
        
        else if(root->right)
        {
            s += "()";
            s+= '(';
            tree2str(root->right);
            s+= ')';
        }
        return s;
    }
    
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    // root->right->left = new TreeNode(5);
    // root->right->right = new TreeNode(6);
    
    cout<<tree2str(root)<<endl;
}
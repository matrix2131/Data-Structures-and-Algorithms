/* 
Given the root node of a binary search tree and two integers low and high, return the 
    sum of values of all nodes with a value in the inclusive range [low, high].

*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

int rangeSumBST(Node* root, int low, int high) {
        if(root == NULL)
            return 0;
        if((root->val == low) && (root->val == high))
            return root->val;
        
        if(root->val >= low && root->val <= high)
            return root->val+ rangeSumBST(root->left,low, high) + rangeSumBST(root->right, low, high);
        
        else if(root->val < low)
            return rangeSumBST(root->right, low, high);
        
        else return rangeSumBST(root->left, low, high);      
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);
    
    // Range of possoble values
    int low = 7, high = 15;
    
    cout<<rangeSumBST(root,low,high)<<endl;
}
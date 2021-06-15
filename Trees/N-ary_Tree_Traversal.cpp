/*
Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. 
Each group of children is separated by the null value.

See examples from leetcode --->  https://leetcode.com/problems/n-ary-tree-preorder-traversal/
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    vector<Node*> children;
    
    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// Preorder Traversal
 void preorder(Node *root, vector<int>& ans)
    {
        if(root == NULL)
            return;
        ans.push_back(root->val);
        for(int i = 0; i<root->children.size(); i++)
        {
            preorder(root->children[i], ans);
        }
    }
    
vector<int> Preorder(Node* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }

// Postorder Traversal    
void postorder(Node *root, vector<int>& ans)
    {
        if(root == NULL)
            return;
        for(int i = 0; i<root->children.size(); i++)
        {
            postorder(root->children[i], ans);
        }
        ans.push_back(root->val);
    }
    
vector<int> Postorder(Node* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
// Maximum Depth of the tree.
int maxDepth(Node* root) {
        if(root == NULL)
            return 0;
        int h = 0;
        for(int i = 0; i<root->children.size(); i++)
        {
            int childh = maxDepth(root->children[i]);
            h = max(h,childh);
        }
        return h+1;
    }

   
int main()
{
    vector<int> pre;
    vector<int> post;
    vector<Node*> childRoot = {new Node(3), new Node(2), new Node(4)};
    Node *root = new Node(1, childRoot);
    vector<Node*> c1 = {new Node(5), new Node(6)};
    root->children[0] = new Node(3,c1);
    
    pre = Preorder(root);
    post = Postorder(root);
    cout<<"Preorder Traversal  ";
    for(int i = 0; i<pre.size(); i++)
        cout<<pre[i]<<" ";
    cout<<endl;

    cout<<"Postorder Traversal  ";
    for(int i = 0; i<post.size(); i++)
        cout<<post[i]<<" "; 
    
    cout<<endl<<"Max depth of tree: "<<maxDepth(root)<<endl;
}
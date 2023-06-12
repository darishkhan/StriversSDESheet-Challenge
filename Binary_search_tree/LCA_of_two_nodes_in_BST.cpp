#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool dfs(TreeNode<int> *root, int x, vector<TreeNode<int>*> &v)
{
    if(root->data == x) 
    {
        v.push_back(root);
        return true;
    }
    bool leftt = false, rightt = false;
    if(root->left) leftt = dfs(root->left, x, v);
    if(leftt) 
    {
        v.push_back(root);
        return true;
    }
    if(root->right) rightt = dfs(root->right, x, v);
    if(rightt) 
    {
        v.push_back(root);
        return true;
    }
    return false;

}
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	// Write your code here
    vector<TreeNode<int>*> v1, v2;
    bool a = dfs(root, P->data, v1);
    bool b = dfs(root, Q->data, v2);
    int i=v1.size()-1, j=v2.size()-1;
    while(i>=0 and j>=0)
    {
        if(v1[i]==v2[j]) {i--;j--;}
        else break;
    }
    return v1[i+1];

}

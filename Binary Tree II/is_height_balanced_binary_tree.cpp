#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int dfs(BinaryTreeNode<int> *root)
{
    int leftt=0, rightt=0;
    if(root->left) leftt = dfs(root->left);
    if(root->right) rightt = dfs(root->right);
    if(leftt==-1 or rightt==-1) return -1;
    if(leftt>rightt+1 or leftt<rightt-1) return -1;
    return max(leftt, rightt)+1;
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    if(root==NULL) return true;
    if(dfs(root)==-1) return false;
    return true;
}

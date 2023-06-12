#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

int dfs(BinaryTreeNode<int> *root)
{
    if(root->left==NULL and root->right==NULL) return root->data;
    int leftt=0, rightt=0;
    if(root->left) leftt=dfs(root->left);
    if(root->right) rightt=dfs(root->right);
    if(leftt+rightt>=root->data) return root->data = leftt+rightt;
    if(root->left) root->left->data = root->data;
    if(root->right) root->right->data = root->data;
    if(root->left) leftt=dfs(root->left);
    if(root->right) rightt=dfs(root->right);
    return root->data = leftt+rightt;

}
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(root==NULL) return;
    int k = dfs(root);
}  

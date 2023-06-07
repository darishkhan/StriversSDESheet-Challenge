#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void dfs(BinaryTreeNode<int> *root, vector<vector<int>> &order)
{
    order[1].push_back(root->data);
    if(root->left) dfs(root->left, order);
    order[0].push_back(root->data);
    if(root->right) dfs(root->right, order);
    order[2].push_back(root->data);

}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> order(3);
    if(!root) return order;
    dfs(root, order);
    return order;
}

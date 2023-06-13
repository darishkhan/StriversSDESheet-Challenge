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
void dfs(BinaryTreeNode<int>* root, vector<int> &inorder)
{
    if(root->left) dfs(root->left, inorder);
    inorder.push_back(root->data);
    if(root->right) dfs(root->right, inorder);

}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    vector<int> inorder;
    dfs(root, inorder);
    BinaryTreeNode<int> * head = new BinaryTreeNode<int>(inorder[0]);
    BinaryTreeNode<int> * prev=head;
    int i=1;
    while(i<inorder.size())
    {
        BinaryTreeNode<int> * node = new BinaryTreeNode<int>(inorder[i]);
        node->left=prev;
        prev->right=node;
        prev=node;
        i++;
    }
    return head;


}

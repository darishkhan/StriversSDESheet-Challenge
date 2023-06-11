/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
int mx=0;
int dfs(TreeNode<int> *root)
{
    int leftt=0, rightt=0;
    if(root->left) leftt = dfs(root->left);
    if(root->right) rightt = dfs(root->right);
    mx=max(mx, leftt+rightt);
    return max(leftt, rightt)+1;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    mx=0;
    if(root==NULL) return 0;
    int k = dfs(root);
    return mx;
}

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

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
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    TreeNode<int>* curr=root;
    if(root==NULL) return curr;
    while(curr)
    {
        if(curr->left)
        {
            TreeNode<int> *pre = curr->left;
            while(pre->right)
            {
                pre=pre->right;
            }
            pre->right = curr->right;
            curr->right= curr->left;
            curr->left=NULL;

        }
        curr=curr->right;
    }
    return root;
}

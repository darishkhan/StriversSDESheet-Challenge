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
int ans;
void trav(TreeNode<int> *root, int &x, int k)
{
    if(root->right==NULL and root->left==NULL)
    {
        x++;
        if(k==x) 
        {
            ans=root->data;
            x=1e5;
        }
        return;
    }
    if(root->right)
    {
        trav(root->right, x, k);
    }
        x++;
        if(k==x)
        {
            ans=root->data;
            x=1e5;
        }
    if(root->left)
    {
        trav(root->left, x ,k);
    }
    // if(k==0) ans=root->data;

}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    ans=-1;
    int x=0;
    trav(root, x, k);
    return ans;
}

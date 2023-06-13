#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int ans=-1;
void solve(TreeNode<int>* root, int key)
{
    if(root->val == key)
    {
        ans=root->val;
        return;
    }
    if(root->val>key) 
    {
        if(root->left) solve(root->left, key);
    }
    if(root->val<key)
    {
        ans=root->val;
        if(root->right) solve(root->right, key);
    }
}
int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    ans=-1;
    solve(root, X);
    return ans;
}

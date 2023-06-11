#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int mx=-1;
int dfs(TreeNode<int> *root)
{
    int leftt=0, rightt=0;
    if(root->left) leftt = dfs(root->left);
    if(root->right) rightt = dfs(root->right);
    if(root->left!=NULL and root->right!=NULL) 
    {
        mx=max(mx, leftt+rightt+root->val);
        // cout<<leftt<<" "<<rightt<<" "<<mx<<"\n";
    }
    return max(leftt, rightt)+root->val;
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    mx=-1;
    if(root==NULL) return -1;
    int k = dfs(root);
    // if(mx==0) return -1;
    return mx;
}

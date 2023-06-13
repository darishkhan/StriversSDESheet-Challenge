#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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
int mx;
int check(TreeNode<int> *root)
{
    if(root->left==NULL and root->right==NULL)
    {
        return 1;
    }
    int leftcheck=1, rightcheck=1;
    if(root->left)
    {
        TreeNode<int> *pre = root->left;
        while(pre->right) {pre=pre->right;}
        if(pre->data>=root->data) leftcheck=0;
    }
    if(root->right)
    {
        TreeNode<int> *pre=root->right;
        while(pre->left) {pre=pre->left;}
        if(pre->data<=root->data) rightcheck=0;
    }
    int leftt=0, rightt=0;
    if(root->left) leftt=check(root->left);
    if(root->right) rightt=check(root->right);
    if(leftcheck==0 or rightcheck==0 or leftt==-1 or rightt==-1)
    {
        return -1;
    }
    mx=max(mx, leftt+rightt+1);
    // if(mx==2) cout<<root->data;
    return leftt+rightt+1;  

}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    mx=1;
    int k = check(root);
    return mx;
}

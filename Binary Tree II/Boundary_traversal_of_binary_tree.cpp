#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
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
void goleft(TreeNode<int>* root, vector<int> &ans)
{
    
    if(root->left) 
    {
        ans.push_back(root->data);
        goleft(root->left, ans);
    }
    else if(root->right)
    {
        ans.push_back(root->data);
        goleft(root->right, ans);
    }
}
void goright(TreeNode<int>* root, vector<int> &ans)
{
    if(root->right)
    {
        goright(root->right, ans);
        ans.push_back(root->data);
    }
    else if(root->left)
    {
        goright(root->left, ans);
        ans.push_back(root->data);
    }
}
void getleaves(TreeNode<int>* root, vector<int> &ans)
{
    if(root->left==NULL and root->right==NULL)
    {
        ans.push_back(root->data);
    }
    if(root->left) getleaves(root->left, ans);
    if(root->right) getleaves(root->right, ans);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(root==NULL) return ans;
    if(root->left or root->right) ans.push_back(root->data);
    if(root->left) goleft(root->left, ans);
    getleaves(root, ans);
    if(root->right) goright(root->right, ans);

    return ans;

}

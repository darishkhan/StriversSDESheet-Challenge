#include <bits/stdc++.h> 
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
void dfs(TreeNode<int> *root, vector<int> &view, int lv, int &mx)
{
    if(lv>mx) view.push_back(root->data);
    mx = max(lv, mx);
    if(root->left)dfs(root->left , view, lv+1, mx);
    if(root->right)dfs(root->right, view, lv+1, mx);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> view;
    if(!root) return view;
    int mx=-1;
    dfs(root, view, 0, mx);
    return view;
}

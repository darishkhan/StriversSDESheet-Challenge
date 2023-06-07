#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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
void dfs(TreeNode<int> *root, vector<int> &view, int pos, int lvl, map<int, pair<int, int>> &m)
{
    if(m.find(pos)!=m.end())
    {
        if(m[pos].first>lvl) m[pos]={lvl, root->val};
    }
    else m[pos]={lvl, root->val};
    if(root->left)dfs(root->left , view, pos-1, lvl+1, m);
    if(root->right)dfs(root->right, view, pos+1, lvl+1, m);
}
vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<int> view;
    map<int, pair<int, int>> m;
    if(!root) return view;
    dfs(root, view, 0, 0, m);
    for(i:m)
    {
        view.push_back(i.second.second);
    }
    return view;
}

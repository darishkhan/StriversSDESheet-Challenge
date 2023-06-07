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
void dfs(TreeNode<int> *root, int lvl, map<int, int> &m)
{
    // if(m.find(lvl)!=m.end())
    // {
    //     m[lvl].first=min(m[lvl].first, pos);
    //     m[lvl].second=max(m[lvl].second, pos);
    // }
    m[lvl]++;
    if(root->left)
    {
        dfs(root->left, lvl+1,  m);
    }
    if(root->right)
    {
        dfs(root->right, lvl+1, m);
    }
}
int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(!root) return 0;
    map<int, int> m;
    dfs(root, 0, m);
    int maxwidth=1;
    for(auto i:m)
    {
        maxwidth = max(maxwidth, i.second);
    }
    return maxwidth;
}

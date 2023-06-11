#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void dfs(BinaryTreeNode<int>*root, map<int, vector<int>> &m, int lvl)
{
    m[lvl].push_back(root->val);
    if(root->left) dfs(root->left, m, lvl+1);
    if(root->right) dfs(root->right, m, lvl+1);
}
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    map<int, vector<int>> m;
    vector<int> ans;
    if(root==NULL) return ans;
    dfs(root, m, 0);
    for(auto i:m)
    {
        for(auto j:i.second)
        {
            ans.push_back(j);
        }
    }
    return ans;
}

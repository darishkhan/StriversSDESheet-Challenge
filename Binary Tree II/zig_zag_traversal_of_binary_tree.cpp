#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void dfs(BinaryTreeNode<int>*root, map<int, vector<int>> &m, int lvl)
{
    m[lvl].push_back(root->data);
    if(root->left) dfs(root->left, m, lvl+1);
    if(root->right) dfs(root->right, m, lvl+1);
}
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    map<int, vector<int>> m;
    vector<int> ans;
    if(root==NULL) return ans;
    dfs(root, m, 0);
    int zig=0;
    for(auto i:m)
    {
        int j, k, step;
        if(zig==0)
        {
            j=0;step=1;k=i.second.size();
        }
        else
        {
            j=i.second.size()-1;step=-1;k=-1;
        }
        while(j!=k)
        {
            ans.push_back(i.second[j]);
            j+=step;
        }
        zig=!zig;
    }
    return ans;
}

#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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
void dfs(BinaryTreeNode<int> *root, vector<int> &view, int pos, int lvl, map<int, pair<int, int>> &m)
{
    if(m.find(pos)!=m.end())
    {
        if(m[pos].first<=lvl) m[pos]={lvl, root->data};
    }
    else m[pos]={lvl, root->data};
    if(root->left)dfs(root->left , view, pos-1, lvl+1, m);
    if(root->right)dfs(root->right, view, pos+1, lvl+1, m);
}
vector<int> bottomView(BinaryTreeNode<int> * root){

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

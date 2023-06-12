#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/
void dfs(BinaryTreeNode<int> *root,  int pos, int lvl, map<int, vector<pair<int, BinaryTreeNode<int>*>>> &m)
{
    m[lvl].push_back({pos, root});
    if(root->left)dfs(root->left , pos-1, lvl+1, m);
    if(root->right)dfs(root->right, pos+1, lvl+1, m);
}
void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    map<int, vector<pair<int, BinaryTreeNode<int>*>>> m;
    dfs(root, 0, 0, m);
    for(auto i:m)
    {
        for(int j=0;j<i.second.size()-1;j++)
        {
            i.second[j].second->next=i.second[j+1].second;
        }
    }

}

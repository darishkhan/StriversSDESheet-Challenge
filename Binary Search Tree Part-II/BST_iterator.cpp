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

class BSTiterator
{
    public:
    queue<int> s;
    void dfs(TreeNode<int> *root)
    {
        if(root->left) dfs(root->left);
        // cout<<root->data<<" ";
        s.push(root->data);
        if(root->right) dfs(root->right);
    }
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        dfs(root);        
    }

    int next()
    {
        // write your code here
        int k = s.front();
        // cout<<k<<" ";
        s.pop();
        return k;
    }

    bool hasNext()
    {
        // write your code here
        // cout<<"ok";
        if(!s.empty()) return true;
        return false;
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/

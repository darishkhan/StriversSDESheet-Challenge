#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
pair<int, int> ans;
void solve(BinaryTreeNode<int>* root, int key)
{
    if(root->data<key) 
    {
        ans.first=root->data;
        if(root->right) solve(root->right, key);
    }
    if(root->data>key) 
    {
        ans.second=root->data;
        if(root->left) solve(root->left, key);
    }
    if(root->data == key)
    {
        if(root->left)
        {
            BinaryTreeNode<int>* pre = root->left;
            while(pre->right)
            {
                pre=pre->right;
            }
            ans.first=pre->data;        
        }
        if(root->right)
        {
            BinaryTreeNode<int>* pre = root->right;
            while(pre->left)
            {
                pre=pre->left;
            }
            ans.second=pre->data;        
        }
        return;
    }
    // if(root->left) solve(root->left, key);
    // if(root->right) solve(root->right, key);

}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    
    ans={-1, -1};
    solve(root, key);
    return ans;
}

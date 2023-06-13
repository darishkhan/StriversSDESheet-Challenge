#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
int ans=-1;
void solve(BinaryTreeNode<int>* root, int key)
{
    if(root->data == key)
    {
        ans=root->data;
        return;
    }
    if(root->data>key) 
    {
        ans=root->data;
        if(root->left) solve(root->left, key);
    }
    if(root->data<key)
    {
        if(root->right) solve(root->right, key);
    }

}
int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    ans=-1;
    solve(node, x);
    return ans;
}

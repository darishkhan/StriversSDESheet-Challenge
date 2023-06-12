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
TreeNode<int>* cons(vector<int> &arr, int i, int j)
{
    if(i>j) return NULL;
    int mid = (i+j)/2;
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);
    root->left = cons(arr, i, mid-1);
    root->right= cons(arr, mid+1, j);
    return root;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    int i=0, j=n-1;
    return cons(arr, i, j);
}

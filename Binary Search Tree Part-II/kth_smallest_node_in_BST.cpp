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
int ans;
void trav(TreeNode<int> *root, int &x, int k)
{
    if(root->right==NULL and root->left==NULL)
    {
        x++;
        if(k==x) 
        {
            ans=root->data;
            x=1e5;
        }
        return;
    }
    if(root->left)
    {
        trav(root->left, x ,k);
    }
        x++;
        if(k==x)
        {
            ans=root->data;
            x=1e5;
        }
    if(root->right)
    {
        trav(root->right, x, k);
    }
    // if(k==0) ans=root->data;

}
int kthSmallest(TreeNode<int> *root, int k)
{
    int x=0;
    trav(root, x, k);
    return ans;
	//	Write the code here.
}

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
TreeNode<int> *dfs(vector<int> &inorder, vector<int> &preorder, int i, int j, int &k)
{
    // if(k>=inorder.size()) return NULL;
    if(i>j) return NULL;
    int flag=false, c;
    // TreeNode<int> node = TreeNode<int>(0);
    TreeNode<int>* root = new TreeNode<int>(0);
    for(c=i;c<=j;c++)
    {
        if(inorder[c]==preorder[k]) 
        {
            flag=true;
            root->data=preorder[k];
            k++;
            break;
        }
    }
    if(!flag) return NULL;
    root->left = dfs(inorder, preorder, i, c-1, k);
    root->right = dfs(inorder, preorder, c+1, j, k);
    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    int i=0, j=inorder.size()-1, k =0;
    TreeNode<int> * g = dfs(inorder, preorder, i, j, k);
    return g;
}

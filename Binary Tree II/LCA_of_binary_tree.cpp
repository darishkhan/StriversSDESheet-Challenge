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
bool dfs(TreeNode<int> *root, int x, vector<int> &v)
{
    if(root->data == x) 
    {
        v.push_back(root->data);
        return true;
    }
    bool leftt = false, rightt = false;
    if(root->left) leftt = dfs(root->left, x, v);
    if(leftt) 
    {
        v.push_back(root->data);
        return true;
    }
    if(root->right) rightt = dfs(root->right, x, v);
    if(rightt) 
    {
        v.push_back(root->data);
        return true;
    }
    return false;

}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    vector<int> v1, v2;
    bool a = dfs(root, x, v1);
    bool b = dfs(root, y, v2);
    int i=v1.size()-1, j=v2.size()-1;
    while(i>=0 and j>=0)
    {
        if(v1[i]==v2[j]) {i--;j--;}
        else break;
    }
    return v1[i+1];
}

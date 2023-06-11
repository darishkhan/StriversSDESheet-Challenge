#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
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

***********************************************************/
bool dfs(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2)
{
    if(root1->data != root2->data) return false;
    int leftt = true, rightt = true;
    if(root1->left==NULL and root2->left==NULL) leftt=true;
    else if(root1->left==NULL or root2->left==NULL) leftt=false;
    else
    {
        leftt = dfs(root1->left, root2->left);
    }
    if(root1->right==NULL and root2->right==NULL) rightt=true;
    else if(root1->right==NULL or root2->right==NULL) rightt=false;
    else
    {
        rightt = dfs(root1->right, root2->right);
    }
    return leftt and rightt;

}
bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here. 	 
    if(root1==NULL and root2==NULL) return true;
    if(root1==NULL or root2==NULL) return false;
    return dfs(root1, root2);
}

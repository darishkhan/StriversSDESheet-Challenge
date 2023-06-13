#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
void dfs(BinaryTreeNode<int> *root, vector<int> &inorder)
{
    if(root->left) dfs(root->left, inorder);
    inorder.push_back(root->data);
    if(root->right) dfs(root->right, inorder);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    vector<int> inorder;
    dfs(root, inorder);
    unordered_map<int,int> m;
    for(int i=0;i<inorder.size();i++)
    {
        m[inorder[i]]=i;
    }
    for(int i=0;i<inorder.size();i++)
    {
        if(m.find(k-inorder[i])!=m.end())
        {
            if(m[k-inorder[i]]>i) return true;
        }
    }
    return false;
}

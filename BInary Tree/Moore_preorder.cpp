#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void func(TreeNode* root, vector<int> &ans)
{
    TreeNode* curr = root;
    while(curr!=NULL)
    {
        // ans.push_back(curr->data);
        if(curr->left==NULL)
        {
            ans.push_back(curr->data);
            curr=curr->right;
        }
        else
        {
            TreeNode* pre = curr->left;
            while(pre->right!=NULL and pre->right!=curr)
            {
                pre=pre->right;
            }
            if(pre->right==NULL)
            {
                pre->right=curr;
                ans.push_back(curr->data);
                curr=curr->left;
            }
            else
            {
                pre->right=NULL;
                // ans.push_back(curr->data);
                curr=curr->right;
            }
        }
    }
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    if(root==NULL) return ans;
    func(root, ans);
    return ans;
}

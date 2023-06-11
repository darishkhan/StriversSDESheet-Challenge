/*****************************************************

    Following is the Binary Tree node structure:
    
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
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool dfs(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2)
{
    if(root1->data != root2->data) return false;
    int leftt = true, rightt = true;
    if(root1->left==NULL and root2->right==NULL) leftt=true;
    else if(root1->left==NULL or root2->right==NULL) leftt=false;
    else
    {
        leftt = dfs(root1->left, root2->right);
    }
    if(root1->right==NULL and root2->left==NULL) rightt=true;
    else if(root1->right==NULL or root2->left==NULL) rightt=false;
    else
    {
        rightt = dfs(root1->right, root2->left);
    }
    return leftt and rightt;

}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here. 
    if(root==NULL) return true;
    if(root->left==NULL and root->right==NULL) return true;
    if(root->left==NULL or root->right==NULL) return false;
    return dfs(root->left, root->right);   
}

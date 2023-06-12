/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int> *dfs(vector<int> &inorder, vector<int> &postorder, int i, int j, int &k)
{
    // if(k>=inorder.size()) return NULL;
    if(i>j) return NULL;
    int flag=false, c;
    // TreeNode<int> node = TreeNode<int>(0);
    TreeNode<int>* root = new TreeNode<int>(0);
    for(c=j;c>=i;c--)
    {
        if(inorder[c]==postorder[k]) 
        {
            flag=true;
            root->data=postorder[k];
            k--;
            break;
        }
    }
    if(!flag) return NULL;
    root->right = dfs(inorder, postorder, c+1, j, k);
    root->left = dfs(inorder, postorder, i, c-1, k);
    return root;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
     int i=0, j=inOrder.size()-1, k=inOrder.size()-1;
     return dfs(inOrder, postOrder, i, j, k);
}

#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

bool dfs(TreeNode<int> *root, int x, vector<int> &path)
{
	if(root->data == x)
	{
		path.push_back(x);
		return true;
	}
	if(root->left)
	{
		if(dfs(root->left, x, path))
		{
			path.push_back(root->data);
			return true;
		}
	}
	if(root->right)
	{
		if(dfs(root->right, x, path))
		{
			path.push_back(root->data);
			return true;
		}
	}
	return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> path;
	bool k = dfs(root, x, path);
	reverse(path.begin(), path.end());
	return path;
}

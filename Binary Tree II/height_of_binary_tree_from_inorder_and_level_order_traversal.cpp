#include <bits/stdc++.h> 
int func(vector<int>& inorder, vector<int>& levelorder, int i, int j, int k, vector<int> &ind)
{
	if(i>=j) return 0;
	int height=0;
	for(int x=k;x<levelorder.size();x++)
	{
		if(ind[levelorder[x]]>=i and ind[levelorder[x]]<=j)
		{
			int left = func(inorder, levelorder, i, ind[levelorder[x]]-1, x+1, ind);
			int right = func(inorder, levelorder, ind[levelorder[x]]+1, j, x+1, ind);
			height = max(left, right)+1;
			break;
		}
	}
	return height;
}

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
	// Write your code here.
	vector<int> ind(N+1);
	for(int i=0;i<N;i++)
	{
		ind[inorder[i]]=i;
	}
	return func(inorder, levelOrder, 0, N-1, 0, ind);

}

#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
	priority_queue<int> q;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<int> ans;
	for(int i=n-1;i>=n-k-1;i--)
	{
		for(int j=n-1;j>=n-k-1;j--)
		{
			q.push(a[i]+b[j]);
		}
	}
	while(k--)
	{
		int p = q.top();
		ans.push_back(p);
		q.pop();
	}
	return ans;
}

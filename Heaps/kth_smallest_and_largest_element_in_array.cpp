#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
	sort(arr.begin(), arr.end());
	vector<int> ans={arr[k-1], arr[n-k]};
	return ans;
}

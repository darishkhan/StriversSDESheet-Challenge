#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;

	int tofind, p1, p2, sum;
	for(int i=0;i<n;i++)
	{
		if(i>0){if(arr[i]==arr[i-1]) continue;}
		tofind = K-arr[i];
		p1 = i+1;
		p2 = n-1;
		while(p1<p2)
		{
			if(arr[p1]==arr[p1-1] and p1!=i+1) {p1++;continue;}
			sum=arr[p1]+arr[p2];
			if(sum==tofind){ans.push_back({arr[p1], arr[p2], arr[i]});p1++;}
			else if(sum<tofind){p1++;}
			else{p2--;}
		}
	}
	return ans;
}

#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here 
	int x = 0, given=0;
	vector<int> count(n, 0);
	for(int i:arr) count[i]++;
	for(int i=1;i<n;i++)
	{
		if(count[i]>1) return i;
	}
}

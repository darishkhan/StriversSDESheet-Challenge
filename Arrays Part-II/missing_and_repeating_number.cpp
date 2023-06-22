#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int x = 0, given=0;
	for(int i=1;i<=n;i++) x=x^i;
	for(int i:arr) given=given^i;
	int got = x^given, j;
	for(int i=0;i<32;i++)
	{
		if(got&(1<<i)) 
		{
			j=i;
			break;
		}
	}
	int a=0, b=0, c=0, d=0;
	for(int i=0;i<n;i++)
	{
		if((i+1)&(1<<j)) c=c^(i+1);
		if(arr[i]&(1<<j)) d=d^arr[i];
	}
	c=c^d;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==c) return {c^got, c};
	}
	return {c, c^got};
	
}

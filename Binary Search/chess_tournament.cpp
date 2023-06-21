#include <bits/stdc++.h> 
int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
	sort(positions.begin(), positions.end());
	int ans, l=1, r=positions[n-1]-positions[0], curr;
	int count=0;
	while(l+1<r)
	{
		ans=(l+r)/2;
		 count=1;
		curr=positions[0];
		for(int i=1;i<n;i++)
		{
			if(positions[i]-curr>=ans) 
			{
				count++;
				curr=positions[i];
			}
		}
		if(count>=c) l=ans;
		else r=ans;
	}
	count=1;
	curr=positions[0];
		for(int i=1;i<n;i++)
		{
			if(positions[i]-curr>=r) 
			{
				count++;
				curr=positions[i];
			}
		}
		if(count>=c) return r;
	count=1;
	curr=positions[0];
		for(int i=1;i<n;i++)
		{
			if(positions[i]-curr>=l) 
			{
				count++;
				curr=positions[i];
			}
		}
		if(count>=c) return l;
		else return -1;
}

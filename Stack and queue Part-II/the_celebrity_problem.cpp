#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	int start=0, end=n-1;
	while(start<end)
	{
		if(knows(start, end))
		{
			start++;
		}
		else
		{
			end--;
		}
	}
	if(start==end) 
	{
		for(int i=0;i<n;i++)
		{
			if(knows(start, i)) return -1;
			if(!knows(i, start) and i!=start) return -1;
		}
	}
	return start;
}

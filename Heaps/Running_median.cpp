#include<bits/stdc++.h>
void findMedian(int *arr, int n)
{
    // Write your code here
    multiset<int> s1, s2;
	for(int i=0;i<n;i++)
	{
		if(s1.empty())
		{
			s1.insert(arr[i]);
			cout<<(*(--s1.end()))<<" ";
			continue;
		}
		if(s2.empty())
		{
			if(arr[i]>=*(--s1.end())) s2.insert(arr[i]);
			else
			{
				int k = *(--s1.end());
				s1.erase(--s1.end());
				s1.insert(arr[i]);
				s2.insert(k);
			}
			cout<<((*(--s1.end())+*(s2.begin()))/2)<<" ";
			continue;
		}
		if(s1.size()==s2.size())
		{
			if(arr[i]<=*s2.begin())
			{
				s1.insert(arr[i]);
			}
			else
			{
				int k = *s2.begin();
				s2.erase(s2.begin());
				s2.insert(arr[i]);
				s1.insert(k);
			}
			cout<<(*(--s1.end()))<<" ";
		}
		else if(s1.size()==s2.size()+1)
		{
			if(arr[i]>=*(--s1.end())) s2.insert(arr[i]);
			else
			{
				int k = *(--s1.end());
				s1.erase(--s1.end());
				s1.insert(arr[i]);
				s2.insert(k);
			}
			cout<<((*(--s1.end())+*(s2.begin()))/2)<<" ";
		}
	}
}

#include<bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	multiset<int> s1, s2;
	vector<int> ans;
	for(int i=0;i<n;i++)
	{
		if(s1.empty())
		{
			s1.insert(arr[i]);
			ans.push_back(*(--s1.end()));
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
			ans.push_back((*(--s1.end())+*(s2.begin()))/2);
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
			ans.push_back(*(--s1.end()));
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
			ans.push_back((*(--s1.end())+*(s2.begin()))/2);
		}
	}
	// for(auto i:s1) cout<<i<<" ";
	// for(auto i:s2) cout<<i<<" ";
	return ans;
}

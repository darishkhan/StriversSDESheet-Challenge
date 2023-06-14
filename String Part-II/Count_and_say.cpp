#include <bits/stdc++.h> 
vector<string> ans(32, "");

int i=0;
string func(string s)
{
	int count=1;
	string t="";
	for(int j=1;j<s.size();j++)
	{
		if(s[j]==s[j-1]) count++;
		else
		{
			t+=to_string(count)+s[j-1];
			count=1;
		}
	}
	t+=to_string(count)+s[s.size()-1];
	return t;

}
string writeAsYouSpeak(int n) 
{
	// Write your code here.
	if(ans[n-1]!="") return ans[n-1];
	ans[0]="1";
	for(;i<n-1;i++)
	{
		ans[i+1]=func(ans[i]);
	}
	i=n-1;
	return ans[n-1];

}

#include <bits/stdc++.h> 
void pushh(stack<int> &s, int k)
{
	if(s.empty())
	{
		s.push(k);
		return;
	}
	if(s.top()>k)
	{
		int c= s.top();
		s.pop();
		pushh(s, k);
		s.push(c);
	}
	else s.push(k);
}
void recur(stack<int> &s)
{
	int k=s.top();
	s.pop();
	if(!s.empty()) recur(s);
	if(s.empty()) 
	{
		s.push(k);
		return;
	}
	pushh(s, k);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	recur(stack);
}

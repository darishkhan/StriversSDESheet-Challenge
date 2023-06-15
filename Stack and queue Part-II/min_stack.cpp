#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	stack<int> s, t;
	int k;
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
			k=0;
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			s.push(num);
			if(t.empty()) t.push(num);
			else if(t.top()<num) t.push(t.top());
			else t.push(num);
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(s.empty()) return -1;
			k=s.top();
			s.pop();t.pop();
			return k;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(s.empty()) return -1;
			k=s.top();
			return k;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(t.empty()) return -1;
			return t.top();
		}
};

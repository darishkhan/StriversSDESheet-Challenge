#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--)
    {
        if(s.empty()) 
        {
            ans[i]=-1;
            s.push(arr[i]);
        }
        else if(s.top()<arr[i])
        {
            ans[i]=s.top();
            s.push(arr[i]);
        }
        else
        {
            while(s.top()>=arr[i])
            {
                s.pop();
                if(s.empty()) break;
            }
            if(s.empty()) ans[i]=-1;
            else ans[i]=s.top();
            s.push(arr[i]);
        }
    }
    // for(int i:ans) cout<<i<<" ";
    return ans;
}

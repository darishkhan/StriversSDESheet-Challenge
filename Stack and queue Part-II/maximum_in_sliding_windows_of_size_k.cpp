#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    priority_queue<pair<int, int>> m;
    vector<int> ans;
    int n = nums.size();
    for(int i=0;i<k;i++)
    {
        m.push({nums[i], i});
    }
    ans.push_back((m.top()).first);
    for(int i=k;i<n;i++)
    {
        while((m.top()).second<=i-k)
        {
            m.pop();
            if(m.empty()) break;
        }
        m.push({nums[i], i});
        ans.push_back((m.top()).first);
    }
    return ans;
}

#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int, int> m;
    for(int i:arr)
    {
        m[i]++;
    }
    set<pair<int, int>> s;
    for(auto i:m)
    {
        s.insert({-1*i.second, i.first});
    }
    auto it = s.begin();
    vector<int> ans;
    for(int i=0;i<k;i++)
    {
        ans.push_back((*it).second); 
        it++;       
    }
    sort(ans.begin(), ans.end());
    return ans;
}

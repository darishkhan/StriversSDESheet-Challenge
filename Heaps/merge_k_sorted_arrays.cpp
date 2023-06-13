#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    multiset<int> m;
    for(auto i:kArrays)
    {
        for(int j=0;j<i.size();j++)
        {
            m.insert(i[j]);
        }
    }
    vector<int> ans;
    for(auto i:m) ans.push_back(i);
    return ans;
}

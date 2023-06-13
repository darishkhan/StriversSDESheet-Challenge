#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
    multiset<int> m;
    set<int> s;
    vector<int> ans;
    for(int i=0;i<k;i++)
    {
        m.insert(arr[i]);
        s.insert(arr[i]);
    }
    // for(auto i:m) cout<<i<<" ";
    //     cout<<endl;
    //     for(auto i:s) cout<<i<<' ';
    //     cout<<endl;
        ans.push_back(s.size());
    for(int i=k;i<arr.size();i++)
    {
        m.erase(m.find(arr[i-k]));
        if(m.find(arr[i-k])==m.end())
        {
            s.erase(arr[i-k]);
        }
        m.insert(arr[i]);
        s.insert(arr[i]);
        // for(auto i:m) cout<<i<<" ";
        // cout<<endl;
        // for(auto i:s) cout<<i<<' ';
        // cout<<endl;
        ans.push_back(s.size());
    }
    return ans;
	
}

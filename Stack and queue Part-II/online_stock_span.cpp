#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    stack<pair<int, int>> s;
    s.push({price[0], 0});
    vector<int> ans;
    ans.push_back(1);
    for(int i=1;i<price.size();i++)
    {
        if(s.top().first<=price[i])
        {
            while(s.top().first<=price[i])
            {
                s.pop();
                if(s.empty()) break;
            }
            if(s.empty()) ans.push_back(i+1);
            else ans.push_back(i-s.top().second);
        }
        else
        {
            ans.push_back(i-s.top().second);
        }
        s.push({price[i], i});
        
    }
    return ans;
}

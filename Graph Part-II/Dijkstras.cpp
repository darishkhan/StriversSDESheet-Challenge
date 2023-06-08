#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    vector<vector<pair<int, int>>> v(vertices+1);
    priority_queue<pair<int, int>> s;
    for(int i=0;i<vec.size();i++)
    {
        v[vec[i][0]].push_back({vec[i][1], vec[i][2]});
        v[vec[i][1]].push_back({vec[i][0], vec[i][2]});
    }
    vector<int> dis(vertices, INT32_MAX);
    dis[0]=0;
    s.push({0, source});
    while(!s.empty())
    {
        pair<int, int> p = s.top();
        s.pop();
        int d = -1*p.first;
        int curr = p.second;
        for(auto i:v[curr])
        {
            if(d+i.second<dis[i.first])
            {
                dis[i.first] = d+i.second;
                s.push({-1*dis[i.first], i.first});
            }
        }
    }
    return dis;

}

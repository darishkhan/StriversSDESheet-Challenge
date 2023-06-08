#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dis(n, 1e9);
    dis[src-1]=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dis[edges[j][0]-1]!=1e9) dis[edges[j][1]-1]=min(dis[edges[j][1]-1], edges[j][2]+dis[edges[j][0]-1]);
            // if(edges[j][2]+dis[edges[j][0]-1]<dis[edges[j][1]-1])
            // {
            //     dis[edges[j][1]-1]=edges[j][2]+dis[edges[j][0]-1];
            // }
        }
    }
    return dis[dest-1];
}

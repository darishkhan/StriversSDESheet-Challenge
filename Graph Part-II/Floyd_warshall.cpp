int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<vector<int>> dis(n, vector<int>(n, 1e9));
    for(int i=0;i<edges.size();i++)
    {
        dis[edges[i][0]-1][edges[i][1]-1]=edges[i][2];
    }
    for(int i=0;i<n;i++) dis[i][i]=0;
    for(int v=0;v<n;v++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dis[i][v]!=1e9 and dis[v][j]!=1e9) dis[i][j]=min(dis[i][j], dis[i][v]+dis[v][j]);
            }
        }
    }
    return dis[src-1][dest-1];
}

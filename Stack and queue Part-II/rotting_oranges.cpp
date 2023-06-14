#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here.
    queue<pair<pair<int, int>, int>> q;
        m = grid.size();
        n = grid[0].size();
        int count0=0, count1=0, count2=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) count1++;
                else if(grid[i][j]==2)
                {
                    count2++;
                    q.push({{i, j}, 0});
                }
                else count0++;
            }
        } 
        if(count1==0) return 0;
        if(count2==0) return -1;
        int time=0;
        while(!q.empty())
        {
            int i=q.front().first.first;
            int j=q.front().first.second;
            time = q.front().second;
            q.pop();
            if(i>0)
            {
                if(grid[i-1][j]==1) 
                {
                    grid[i-1][j]=2;
                    q.push({{i-1, j}, time+1});    
                    count1--;count2++;            
                }
            }
            if(j>0)
            {
                if(grid[i][j-1]==1)
                {
                    grid[i][j-1]=2;
                    q.push({{i,j-1}, time+1});
                    count1--;count2++; 
                }
            }
            if(i<m-1)
            {
                if(grid[i+1][j]==1)
                {
                    grid[i+1][j]=2;
                    q.push({{i+1, j}, time+1});
                    count1--;count2++; 
                }
            }
            if(j<n-1)
            {
                if(grid[i][j+1]==1)
                {
                    grid[i][j+1]=2;
                    q.push({{i,j+1}, time+1});
                    count1--;count2++; 
                }
            }
        }
        if(count1==0) return time;
        return -1; 
}

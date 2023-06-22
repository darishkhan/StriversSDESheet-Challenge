void place(vector<vector<int>> &chess, vector<int> &hor, vector<int> &ver, int a, int b, int &count, vector<vector<int>> &ans)
{
    int n = chess.size();
    int i=a;
    if(i==n) return;
    for(int j=b;j<n;j++)
    {
        if(hor[i]==0 and ver[j]==0 )
        {
            int p=i, q=j, flag=0;
            while(p>=0 and q>=0)
            {
                if(chess[p][q]==1) 
                {flag=1;break;}
                p--;q--;
            }
            if(flag) continue;
            p=i;q=j;
            while(p>=0 and q<=n-1)
            {
                if(chess[p][q]==1) 
                {flag=1;break;}
                p--;q++;
            }
            if(flag) continue;
            // cout<<i<<" "<<j<<"\n";
            count++;
            chess[i][j]=1;
            hor[i]=1;
            ver[j]=1;
            if(count==n) 
            {
                vector<int> c;
                for(int x=0;x<n;x++)
                {
                    for(int y=0;y<n;y++)
                    {
                        c.push_back(chess[x][y]);
                    }
                }
                ans.push_back(c);
            }
            
            place(chess, hor, ver, i+1, 0, count, ans);
            count--;
            chess[i][j]=0;
            hor[i]=0;
            ver[j]=0;
        }
    }
    
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> chess(n, vector<int>(n, 0));
    vector<int> hor(n, 0), ver(n, 0);
    // set<int> diag;
    int  count=0;
    vector<vector<int>> ans;
    place(chess, hor, ver,  0, 0, count, ans);
    return ans;
    
}

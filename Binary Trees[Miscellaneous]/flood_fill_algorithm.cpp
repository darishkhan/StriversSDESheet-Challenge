void dfs(vector<vector<int>> &image, int x, int y, int from, int to, vector<vector<int>> &vis)
{
    vis[x][y]=1;
    image[x][y]=to;
    int trav[4][2]={{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for(int i=0;i<4;i++)
    {
        int newx = x+trav[i][0];
        int newy = y+trav[i][1];
        if(newx>=0 and newy>=0 and newx<image.size() and newy<image[0].size())
        {
            if(!vis[newx][newy] and image[newx][newy]==from)
            {
                dfs(image, newx, newy, from, to, vis);
            }
        }
    }
    
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    vector<vector<int>> vis(image.size(), vector<int>(image[0].size(), 0));
    dfs(image, x, y, image[x][y], newColor, vis);
    return image;

}

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans = arr[0];
    for(int i=0;i<n;i++)
    {
        int j, lim = min(ans.size(), arr[i].size());
        for(j=0;j<lim;j++)
        {
            if(ans[j]!=arr[i][j]) break;
        }
        if(j<ans.size()) ans = ans.substr(0, j);
    }
    return ans;
}



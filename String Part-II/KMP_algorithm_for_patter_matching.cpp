#include <bits/stdc++.h> 
bool findPattern(string p, string s)
{
    // Write your code here.
    int m = p.size(), n=s.size();
    if(n<m) return false;
    int lis[m+1]={0};
    int len=0, i=2;
    while(i<=m)
    {
        if(p[len]==p[i-1]) 
        {
            len++;
            lis[i]=len;
            i++;
        }
        else if(len!=0) len=lis[len];
        else 
        {
            lis[i]=0;
            i++;           
        }
    }
    int j=0, count=0;i=0;
    while(i<n)
    {
        if(s[i]==p[j]) 
        {
            i++;j++;
        }
        else if(j==0) i++;
        else j=lis[j];
        if(j==m) return true;
    }
    return false;
}

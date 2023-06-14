#include <bits/stdc++.h> 
int64_t toint(string s)
{
    int64_t number=0;
    for(int i=0;i<s.size();i++)
    {
        number=number*10+(s[i]-'0');
    }
    return number;
}
vector<int64_t> func(string s)
{
    int64_t dot=-1, n=s.size();
    vector<int64_t> v;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='.')
        {
            v.push_back(toint(s.substr(dot+1, i-dot-1)));
            dot=i;            
        }
    }
    if(dot!=n-1) v.push_back(toint(s.substr(dot+1, n-1-dot)));
    // for(i:v) cout<<i<<" ";
    return v;
}
int compareVersions(string a, string b) 
{
    // Write your code here
    vector<int64_t> v1, v2;
    v1=func(a);
    v2=func(b);
    int lim=min(v1.size(), v2.size());
    for(int i=0;i<lim;i++)
    {
        if(v1[i]>v2[i]) return 1;
        if(v2[i]>v1[i]) return -1;
    }
    if(v1.size()>v2.size())
    {
        for(int i=lim;i<v1.size();i++)
        {
            if(v1[i]>0) return 1;
        }
    }
    else if(v1.size()<v2.size())
    {
        for(int i=lim;i<v2.size();i++)
        {
            if(v2[i]>0) return -1;
        }
    }
    return 0;
}

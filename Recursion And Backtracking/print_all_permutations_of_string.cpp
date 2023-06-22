#include <bits/stdc++.h> 
void perm(string s, int j, vector<string> &ans)
{
    if(j==s.size()-1) ans.push_back(s);
    for(int i=j;i<s.size();i++)
    {
        string t=s;
        swap(t[i], t[j]);
        perm(t, j+1, ans);
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    perm(s, 0, ans);
    return ans;
}

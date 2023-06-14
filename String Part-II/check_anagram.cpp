#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    if(str1.size()!=str2.size()) return 0;
    int m1[26]={0};
    int m2[26]={0};
    for(int i=0;i<str1.size();i++)
    {
        m1[str1[i]-'a']++;
        m2[str2[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(m1[i]!=m2[i]) return 0;
    }
    return 1;
}

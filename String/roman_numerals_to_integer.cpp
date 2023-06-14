#include <bits/stdc++.h> 
int val(char s)
{
    if(s=='I') return 1;
    if(s=='V') return 5;
    if(s=='X') return 10;
    if(s=='L') return 50;
    if(s=='C') return 100;
    if(s=='D') return 500;
    if(s=='M') return 1000;
}
int romanToInt(string s) {
    // Write your code here
    int sum=0;
    for(int i=0;i<s.size()-1;i++)
    {
        if(val(s[i])<val(s[i+1])) sum-=val(s[i]);
        else sum+=val(s[i]);
    }
    sum+=val(s[s.size()-1]);
    return sum;
}

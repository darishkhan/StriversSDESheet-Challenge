#include <bits/stdc++.h> 
int atoi(string str) {
    // Write your code here.
    int number=0;

    for(int i=0;i<str.size();i++)
    {
        if(str[i]<='9' and str[i]>='0')
        {
            number=number*10+(str[i]-'0');
        }
    }
    if(str[0]=='-') number*=-1;
    return number;
}

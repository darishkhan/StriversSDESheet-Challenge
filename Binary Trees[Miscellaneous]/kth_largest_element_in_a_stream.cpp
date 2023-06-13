#include <bits/stdc++.h> 
class Kthlargest {
public:
    multiset<int> s1, s2;
    int c;
    Kthlargest(int k, vector<int> &arr) {
       // Write your code here.
       c=k;
       for(int i=0;i<arr.size();i++)
       {
           s2.insert(arr[i]);
           if(s2.size()>c) 
           {
               s1.insert(*s2.begin());
               s2.erase(s2.begin());
           }
       }
    }

    void add(int num) {
        // Write your code here.
        s2.insert(num);
        if(s2.size()>c) 
        {
            s1.insert(*s2.begin());
            s2.erase(s2.begin());
        }
    }

    int getKthLargest() {
       // Write your code here.
       return *s2.begin();
    }

};

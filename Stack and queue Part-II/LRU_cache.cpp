#include<bits/stdc++.h>
class LRUCache
{
    private:
    list<int> q;
    map<int, list<int>::iterator> m;
    map<int, int> v;
    int cap;
public:
    LRUCache(int capacity)
    {
        // Write your code here
        cap=capacity;
    }

    int get(int key)
    {
        // Write your code here
        if(m.find(key)!=m.end())
        {
            q.erase(m[key]);
            q.push_front(key);
            m[key]=q.begin();
            return v[key];
        }
        return -1;

    }

    void put(int key, int value)
    {
        // Write your code here
        if(m.find(key)!=m.end())
        {
            q.erase(m[key]);
            q.push_front(key);
            m[key]=q.begin();
            v[key]=value;
        }
        else
        {
            // cout<<"\n"<<cap<<" "<<q.size()<<" \n";
            if(q.size()==cap) 
            {
                int k = *(--q.end());
                // cout<<k;
                q.pop_back();
                m.erase(k);
                v.erase(v.find(k));
            }
            q.push_front(key);
            m[key]=q.begin();
            v[key]=value;

        }

    }
};

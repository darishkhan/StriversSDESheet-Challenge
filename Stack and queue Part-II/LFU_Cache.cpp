//leetcode

class LFUCache {
public:
    set<pair<int, pair<int, int>>> s;
    unordered_map<int, int> freq;
    unordered_map<int, int> tm;
    unordered_map<int, int> mp;
    int cap, time;
    
    LFUCache(int capacity) {
        cap=capacity;
        time=0;
    }
    
    int get(int key) {
        time++;
        if(freq.find(key)!=freq.end())
        {
            int t = tm[key];
            auto it = s.find({freq[key], {t, key }});
            s.erase(it);
            s.insert({freq[key]+1, {time, key}});
            freq[key]++;
            tm[key]=time;
            return mp[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        time++;
        if(freq.find(key)!=freq.end())
        {
            int count = freq[key];
            int t = tm[key];
            auto it = s.find({count, {t, key}});
            s.insert({count+1, {time, key}});
            s.erase(it);
            freq[key]++;
            mp[key]=value;
            tm[key]=time;
            return;
        }
        if(mp.size()==cap)
        {
            auto it = s.begin();

            mp.erase((*it).second.second);
            freq.erase((*it).second.second);
            tm.erase((*it).second.second);
            s.erase(it);
        }
        mp[key]=value;
        freq[key]++;
        s.insert({1, {time, key}});
        tm[key]=time;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

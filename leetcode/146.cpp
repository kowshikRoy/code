/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-10
 * Task: 146
 */

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = H.find(key);
        if(it == H.end()) return -1;
        touch(it.second);
        it.second = L.begin();
        return L.begin()->second;
    }
    
    void put(int key, int value) {
        auto it = H.find(key);
        if(it == H.end() && H.size() == cap) {
            auto item = L.back();
            L.pop_back();
            H.erase(item.first);
            L.push_front({key,value});
            H[key] = L.begin();
            return
        }
        touch(it)


        
    }
private:
    unordered_map<int,list<pair<int,int>>::iterator> H;
    list<pair<int,int>> L;
    int cap;

    void touch(list<pair<int,int>>::iterator it) {
        L.erase(it);
        L.push_front(*it);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

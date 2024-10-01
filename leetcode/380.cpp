/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-15
 * Task: 380
 */

#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
    vector<int> v;
    unordered_map<int, int> H;

   public:
    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already
     * contain the specified element. */
    bool insert(int val) {
        if (H.count(val) == 0) {
            H[val] = v.size();
            v.push_back(val);
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the
     * specified element. */
    bool remove(int val) {
        if (H.count(val)) {
            int idx   = H[val];
            v[idx]    = v.back();
            H[v[idx]] = idx;
            v.pop_back();

            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % v.size();
        return v[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

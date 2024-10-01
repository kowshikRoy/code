/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-10
 * Task: 379
 */

#include <bits/stdc++.h>
using namespace std;

class PhoneDirectory {
   public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone
       directory. */
    int cap;
    unordered_set<int> available;

    PhoneDirectory(int maxNumbers) {
        cap = maxNumbers;
        for (int i = 0; i < cap; i++) available.insert(i);
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */

    int get() {
        if (available.empty()) return -1;
        int k = *available.begin();
        available.erase(available.begin());
        return k;
    }

    /** Check if a number is available or not. */
    bool check(int number) { return available.count(number); }

    /** Recycle or release a number. */
    void release(int number) { available.insert(number); }
};

int main() { return 0; }

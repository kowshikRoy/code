/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-27
 * Task: 217 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> H;
        for(auto x: nums) {
            if(H.count(x)) return true;
            H.insert(x);
        }
        return false;
        
    }
};


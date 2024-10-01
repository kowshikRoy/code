/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-15
 * Task: 49
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> out;
        for (auto s : strs) {
            auto t = s;
            sort(t.begin(), t.end());
            out[t].push_back(s);
        }
        vector<vector<string>> result;
        for (auto v : out) result.push_back(v.second);
        return result;
    }
};

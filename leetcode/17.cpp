/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-27
 * Task: 17
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        string cur;
        if(digits.size() == 0) return ret;
        vector<string> ph(10);
        ph[2] = "abc";
        ph[3] = "def";
        ph[4] = "ghi";
        ph[5] = "jkl";
        ph[6] = "mno";
        ph[7] = "pqrs";
        ph[8] = "tuv";
        ph[9] = "wxyz";
        int n                   = (int)digits.size();
        function<void(int)> rec = [&](int idx) -> void {
            if (idx == n) {
                ret.push_back(cur);
                return;
            }
            int v = digits[idx] - '0';
            for (int i = 0; i < ph[v].size(); i++) {
                cur.push_back(ph[v][i]);
                rec(idx + 1);
                cur.pop_back();
            }
        };

        rec(0);
        return ret;
    }
};

/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-25
 * Task: 438
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        int n = (int)p.length();
        vector<int> cnt(26, 0);
        for (char c : p) cnt[c - 'a']++;
        int diff = 0;
        for (int i = 0; i < 26; i++)
            if (cnt[i]) diff++;

        vector<int> ans;
        for (int l = 0, r = 0; r < s.size(); r++) {
            char c = s[r] - 'a';
            if (--cnt[c] == 0) diff--;

            if (diff == 0) { ans.push_back(l); }
            if (r >= n) {
                if (++cnt[s[l]] == 1) diff++;
            }
        }
        return ans;
    }
};

/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-27
 * Task: 242
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        sort(words.begin(), words.end(),
             [](string &a, string &b) { return a.length() < b.length(); });

        unordered_set<string> d_words[1004];
        vector<string> ans;
        for (string s : words) {
            int n         = (int)s.size();
            int dp[n + 1] = {0};
            dp[n]         = 1;
            for (int i = n - 1; i >= 0; i--) {
                for (int len = 1; i + len <= n && len < n; len++) {
                    if (dp[i + len] && d_words[len].count(s.substr(i, len))) {
                        dp[i] = 1;
                        break;
                    }
                }
            }
            d_words[n].insert(s);
            if (dp[0]) ans.push_back(s);
        }

        return ans;
    }
};

/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-07
 * Task: 459
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
   public:
    /**
     * Z[i] is the length of the longest substring starting from S[i] which is
     * also a prefix of S the maximum k such that S[j] = S[i + j] for all
     * 0 ≤ j < k
     */
    vector<int> comp_z(string &s) {
        int R = 0, L = 0;
        int n = (int)s.length();
        vector<int> Z(n);
        for (int i = 1; i < n; i++) {
            if (i > R || Z[i - L] >= R - i + 1) {
                L = i;
                R = max(i, R);
                while (R < n && s[R] == s[R - L]) R++;
                Z[i] = R - L;
                R--;
            } else
                Z[i] = Z[i - L];
        }
        return Z;
    }

    bool repeatedSubstringPattern(string s) {
        auto z = comp_z(s);
        int n  = (int)s.length();
        for (int i = 0; i < n; i++) {
            if (i + z[i] == n && n % (n - z[i]) == 0) {
                dbg(i, z[i]);
                return true;
            }
        }
        return false;
    }
};

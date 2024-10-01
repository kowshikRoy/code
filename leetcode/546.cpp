/**
 * Author: Repon Kumar Roy
 * Date: 2021-09-08
 * Task: 546
 */

#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
    os << '{';
    string sep;
    for (const T &x : v) os << sep << x, sep = ", ";
    return os << '}';
}

void dbg_out() { cerr << "]" << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
    cerr << H;
    if (sizeof...(T)) cerr << ", ";
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...)                                                       \
    cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", \
        dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

using namespace std;
class Solution {
public:
    int removeBoxes(vector<int> &a) {
        int n = (int)a.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        function<int(int, int)> rec = [&](int i, int j) -> int {
            if (i == j) return 1;
            if (i > j) return 0;
            int &ans = dp[i][j];
            if (ans != -1) return ans;

            ans                  = 0;
            int firstNonMatching = n + 1, lastNonMatching = i - 1, cnt = 0,
                tot = 0;
            for (int k = i; k <= j; k++) {
                if (a[k] == a[i]) {
                    cnt++;
                    tot += rec(firstNonMatching, lastNonMatching);
                    ans = max(ans, cnt * cnt + tot + rec(k + 1, j));
                    firstNonMatching = n + 1, lastNonMatching = i - 1;
                } else {
                    firstNonMatching = min(firstNonMatching, k);
                    lastNonMatching  = k;
                }
            }
            return ans;
        };
        return rec(0, n - 1);
    }
};
int main() {
    vector<int> a = {1, 3, 2, 2, 2, 3, 4, 3, 1};
    cout << Solution().removeBoxes(a) << endl;
}

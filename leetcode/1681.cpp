/**
 * Author: Repon Kumar Roy
 * Date: 2021-08-27
 * Task: 1681
 */

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << "]" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H; if(sizeof...(T)) cerr << ", "; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

class Solution {
public:
    int minimumIncompatibility(vector<int> &nums, int k) {
        // mask is an integer, where if ith bit of mask = 0, that means, ith
        // element is not taken, otherwise taken dp[mask] = Minimum sum of
        // imcompatibility for state mask

        const int n = (int)nums.size(), INF = INT_MAX / 4;
        vector<int> dp(1<<n, -1);
        vector<vector<int>> check(1<<n, vector<int>(n));
        for(int i = 0; i < 1<< n; i ++) {
            unordered_set<int> s;
            for(int k = 0; k < n; k ++) {
                if((i & (1<<k))) s.insert(nums[k]);
            }
            for(int j = 0; j < n; j ++) {
                if(s.count(nums[j])) check[i][j] = false;
                else check[i][j] = true;
            }
        }

        function<int(int)> rec;

        int k1 = n / k;


        function<void(int, vector<int> &, vector<int> &, int, int &)> dfs =
            [&](int mask, vector<int> &taken, vector<int> &list, int cur,
                int &ans) -> void {
            if (taken.size() == k1) {
                int iMax = INT_MIN, iMin = INT_MAX;
                for(auto x: taken) {
                    iMax= max(iMax, nums[x]);
                    iMin = min(iMin, nums[x]);
                }
                dbg(taken);
                for(int i = 0; i < n; i ++) cout << ((mask & (1<<i)) ? 1 : 0);
                cout<<endl;
                ans = min(ans, iMax - iMin + rec(mask));
                return;
            }
            if(cur == list.size()) return;
            if(check[mask][list[cur]]) {
                taken.push_back(list[cur]);
                dfs(mask | (1 << list[cur]), taken, list, cur + 1, ans);
                taken.pop_back();
            }

            dfs(mask, taken, list, cur + 1, ans);
        };

        rec = [&](int mask) -> int {
            if (mask == (1 << n) - 1) return 0;
            int &ans = dp[mask];
            if (ans != -1) return ans;
            ans = INF;

            int pivot;
            for (int i = 0; i < n; i++)
                if ((mask & (1 << i)) == 0) {
                    pivot = i;
                    break;
                }

            vector<int> list;
            vector<int> taken;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) == 0 && i != pivot) { list.push_back(i); }
            }
            taken.push_back(pivot);
            dfs(mask | (1 << pivot), taken, list, 0, ans);
            return ans;
        };

        dbg(nums);
        return rec(0);
    }
};

int main() {
    vector<int> nums=  {6,3,8,1,3,1,2,2};
    cout<< Solution().minimumIncompatibility(nums, 4) << endl;
}

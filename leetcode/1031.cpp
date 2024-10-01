/**
 * Author: Repon Kumar Roy
 * Date: 2021-08-21
 * Task: 1031
 */

#include <bits/stdc++.h>
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

using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(helper(nums, firstLen, secondLen), helper(nums, secondLen, firstLen));
    }
    int helper(vector<int>&nums, int x, int y) {
        int i = 0, n = (int)nums.size();
        int maxf = 0, curs = 0, curf = 0, ans = 0;
        for(; i < x; i ++) maxf += nums[i];
        for(; i < x + y; i ++) curs += nums[i];
        curf = maxf;
        ans = maxf + curs;
        for(int l = 0, r = x; i < n; i ++, l ++, r ++) {
            curs += nums[i] - nums[i - y];
            curf += nums[r] - nums[l];
            maxf = max(maxf, curf);
            ans = max(ans, maxf + curs);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1,0,3};
    cout << Solution().maxSumTwoNoOverlap(nums, 1, 2) << endl;
}

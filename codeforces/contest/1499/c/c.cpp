/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-20
 * Task: c
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> c(n + 1);
        vector<long long> odd_pfsum(n + 1), even_pfsum(n + 1);
        vector<long long> cnt_odd(n + 1), cnt_even(n + 1);
        for (int i = 1; i <= n; i++) cin >> c[i];
        for (int i = 1; i <= n; i++) {
            odd_pfsum[i]  = odd_pfsum[i - 1];
            cnt_odd[i]    = cnt_odd[i - 1];
            cnt_even[i]   = cnt_even[i - 1];
            even_pfsum[i] = even_pfsum[i - 1];
            if (i & 1) odd_pfsum[i] += c[i], cnt_odd[i]++;
            else
                even_pfsum[i] += c[i], cnt_even[i]++;
        }

        c[0]              = INT_MAX;
        int odd_index     = 1;
        int even_index    = 0;
        long long odd_sum = 0, even_sum = 0;

        long long ans = LLONG_MAX;
        for (int k = 2; k <= n; k++) {
            if (k & 1) {
                if (c[k] < c[odd_index]) odd_index = k;
            } else {
                if (c[k] < c[even_index]) even_index = k;
            }
            long long p1 = odd_pfsum[k] + (n - cnt_odd[k]) * c[odd_index];
            long long p2 = even_pfsum[k] + (n - cnt_even[k]) * c[even_index];
            ans          = min(ans, p1 + p2);
        }
        cout << ans << endl;
    }
}

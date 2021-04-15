/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-13
 * Task: 10785
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> val(26);
    REP(i, 26) val[i] = i % 9 + 1;

    int t, cs = 0;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> use(26, 0);
        auto isvowel = [&](int u) {
            char c = u + 'A';
            return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        };

        REP(i, 26) {
            if (isvowel(i)) use[i] = 21;
            else
                use[i] = 5;
        }

        string even, odd;
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                int iMin  = 1000;
                int pivot = -1;
                for (int j = 0; j < 26; j++) {
                    if (isvowel(j)) continue;
                    if (use[j] == 0) continue;
                    if (use[j] && val[j] < iMin) {
                        pivot = j;
                        iMin  = val[j];
                    }
                }
                assert(pivot != -1);
                assert(use[pivot] > 0);
                use[pivot]--;
                even.push_back(pivot + 'A');
            } else {
                int iMin  = 1000;
                int pivot = -1;
                for (int j = 0; j < 26; j++) {
                    if (!isvowel(j)) continue;
                    if (use[j] == 0) continue;
                    if (use[j] && val[j] < iMin) {
                        pivot = j;
                        iMin  = val[j];
                    }
                }
                assert(pivot != -1);
                assert(use[pivot] > 0);
                use[pivot]--;
                odd.push_back(pivot + 'A');
            }
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        string ans;
        int o = 0, e = 0;
        for(int i = 0; i < n; i ++) {
            if(i & 1) ans.push_back(even[e++]);
            else ans.push_back(odd[o++]);
        }
        cout << "Case " << ++cs << ": " << ans << endl;
    }
    return 0;
}

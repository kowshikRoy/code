#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> ptr[N];
vector<int> pivot;
void process(string &s) {
    vector<int> cur(26, -1);
    for (int i = (int)s.length(); i >= 0; i--) {
        ptr[i]          = cur;
        cur[s[i] - 'a'] = i;
    }
    pivot = cur;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        string s, t;
        cin >> s;
        cin >> t;
        process(s);
        int turn      = 0;
        bool possible = 1;
        for (int i = 0; i < t.size();) {
            turn++;
            int p = pivot[t[i] - 'a'];
            if (p == -1) {
                possible = 0;
                break;
            }
            int j = i;
            while (p < s.size() && j < t.size()) {
                j++;
                if (j < t.size()) p = ptr[p][t[j] - 'a'];
            }
            if (i == j) {
                possible = 0;
                break;
            }
            i = j;
        }
        printf("%d\n", possible ? turn : -1);
    }

    return 0;
}

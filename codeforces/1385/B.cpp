#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<int> s;
        for (int i = 0; i < 2 * n; i++) {
            int x;
            cin >> x;
            if (s.count(x) == 0) cout << x << " ";
            s.insert(x);
        }
        cout << endl;
    }

    return 0;
}

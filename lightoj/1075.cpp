#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, s, cs = 0;
    cin >> t;
    while (t--) {
        unordered_map<string, string> nxt;
        unordered_map<string, int> deg;

        cin >> s;
        for (int i = 0; i < s - 1; i++) {
            string a, b;
            cin >> a >> b;
            nxt[a] = b;
            deg[a]++;
            deg[b]--;
        }
        string root;
        for (auto a : deg)
            if (a.second == 1) root = a.first;
        cout << "Case " << ++cs << ":\n";
        cout << root << endl;
        while (nxt.count(root)) {
            root = nxt[root];
            cout << root << endl;
        }
        cout << endl;
    }
}

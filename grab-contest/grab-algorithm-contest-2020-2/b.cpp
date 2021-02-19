#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        int A = 0, B = 0;
        for (int i = 0; i < a.size(); i++) A = (1 << (a[i] - 'a'));
        for (int i = 0; i < b.size(); i++) B = (1 << (a[i] - 'a'));

        printf("%s\n", (A & B) > 0 ? "YES" : "NO");
    }

    return 0;
}

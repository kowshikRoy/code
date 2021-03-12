/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-12
 * Task: 1621
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }
    cout << s.size() << endl;
}

#include <cstdio>
#include <iostream>
using namespace std;

pair<bool, int> solve() {
    int x, a, y, b;
    cin >> x >> a >> y >> b;
    pair<bool, int> p1, p2;
    if (x == 0) p1 = solve();
    else
        p1 = make_pair(true, x);
    if (y == 0) p2 = solve();
    else
        p2 = make_pair(true, y);

    if (p1.first && p2.first && a * p1.second == b * p2.second)
        return make_pair(true, p1.second + p2.second);
    return make_pair(false, 0);
}
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        printf("%s\n", solve().first ? "YES" : "NO");
        if (tc) printf("\n");
    }
}

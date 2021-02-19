#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> big;
priority_queue<int> small;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    while (n--) {
        int a;
        cin >> a;
        cnt++;
        if (big.size() == 0 || big.top() <= a) big.push(a);
        else
            small.push(a);

        while (big.size() > 1 + small.size()) {
            int x = big.top();
            big.pop();
            small.push(x);
        }

        while (small.size() > big.size()) {
            int x = small.top();
            small.pop();
            big.push(x);
        }

        /* printf("----> %d %d\n", big.size() ? big.top() : 0, small.size() ?
         * small.top(): 0); */

        double ans = 0;
        if (cnt % 2 == 0) {
            ans = (small.top() + big.top()) / 2.0;
        } else
            ans = big.top();
        printf("%.1lf\n", ans);
    }
}

#include <cstdio>
#include <iostream>

using namespace std;
const int N      = 1e5 + 5;
const double EPS = 1e-7;
int l[N], s[N], v[N];
double sumLength[N];
int n;
int main() {
    while (cin >> n) {
        for (int i = 0; i <= n; i++) {
            scanf("%d", &l[i]);
            if (i > 0) sumLength[i] = l[i] + sumLength[i - 1];
        }
        for (int i = 0; i <= n; i++) scanf("%d", &s[i]);
        for (int i = 0; i <= n; i++) scanf("%d", &v[i]);
        double ans = 0;
        for (int i = n; i >= 0; i--) {
            double x = sumLength[i] + s[i];
            ans      = max(ans, x / v[i]);
        }

        printf("%.15lf\n", ans);
    }
}

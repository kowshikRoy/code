#include <bits/stdc++.h>
using namespace std;
int sumDigit(int n) {
    int sum = 0;
    while (n) sum += n % 10, n /= 10;
    return sum;
}
int main() {
    int n;
    int iMax = 0, ans = -1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            if (sumDigit(i) > iMax) {
                iMax = sumDigit(i);
                ans  = i;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

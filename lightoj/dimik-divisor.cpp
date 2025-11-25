#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        int n;
        cin >> n;
        vector<int> divisors;
        for(int i = 1; i * i <= n; i ++) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i != n / i) {
                    divisors.push_back(n / i);
                }
            }
        }
        sort(divisors.begin(), divisors.end());
        printf("Case %d: ", cs);
        for (int i = 0; i < divisors.size(); i ++) {
            if (i) cout << " ";
            cout << divisors[i];
        }
        cout << "\n";
    }
    return 0;
}
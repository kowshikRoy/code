#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        long long n;
        cin >> n;
        bool neg = false;
        if (n < 0) {
          neg = true;
        }
        n = abs(n);
        long long s = 0;
        while(n) {
          s = 10 *s + n%10;
          n /= 10;
        }
        if(neg) s = -s;
        cout << s << endl;
    }
}

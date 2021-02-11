#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        int pos = k;
        for(int i = 0; i <= pos; i ++ ) {
            if(pos < i) break;
            pos = (n - 1) - (pos - i);
        }
        cout << pos << endl;
    }
}

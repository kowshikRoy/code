#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                if(j) cout << " ";
                cout << m;
            }
            cout << "\n";
        }
        for (int i = n - 1; i >= 1; i--) {
            for(int j = 0; j < i; j++) {
                if(j) cout << " ";
                cout << m;
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}

#include <iostream>

using namespace std;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long a,b,c;
        cin >> a >> b >> c;
        long long f = ((a + c - 1) / c) * c;
        for(; f <= b; f += c) {
            cout << f << "\n";
        }
        cout << "\n";
    }
    return 0;
}

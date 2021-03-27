#include <iostream>

using namespace std;

int main() {
    int t, cs = 0;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        bool x = (n % 7) >= 2;
        printf("Case %d: %s\n", ++cs,
               x ? "No eggs for you! :D" : "Oh no, my eggs! :(");
    }
    return 0;
}

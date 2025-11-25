#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        double x, y, x_c, y_c, r;
        cin >> x_c >> y_c >> r >> x >> y;
        double dist = (x - x_c) * (x - x_c) + (y - y_c) * (y - y_c);
        r = r * r;
        if (dist < r) {
            printf("The point is inside the circle\n");
        } else {
            printf("The point is not inside the circle\n");
        }
    }
    return 0;
}

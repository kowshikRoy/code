#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        double a, b, c;
        std::cin >> a >> b >> c;
        double s = (a + b + c) / 2.0;
        double area = std::sqrt(s * (s - a) * (s - b) * (s - c));
        std::cout << std::fixed << std::setprecision(3) << "Area = " << area << std::endl;
    }
    return 0;
}

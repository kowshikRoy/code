#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int main() {
    int t;
    std::cin >> t;
    vector<int> vec = { 6, 28, 496, 8128, 33550336};
    
    while (t--) {
        int n;
        cin >> n;
        for(int i = 0; i < vec.size(); i ++) {
            if(vec[i] > n) {
                break;
            }
            cout << vec[i] << "\n";
        }
        cout << "\n";
    }
    return 0;
}

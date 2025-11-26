#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        vector<int> cpy(arr.begin(), arr.end());
        sort(cpy.begin(), cpy.end());
        if (arr == cpy) {
            cout << "YES" << endl;
            continue;
        }
        reverse(cpy.begin(), cpy.end());
        if (arr == cpy) {
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;
    }
    return 0;
}

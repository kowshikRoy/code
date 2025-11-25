#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n1;
        std::cin >> n1;
        std::vector<int> arr1(n1);
        for (int i = 0; i < n1; ++i) {
            std::cin >> arr1[i];
        }

        int n2;
        std::cin >> n2;
        std::vector<int> arr2(n2);
        for (int i = 0; i < n2; ++i) {
            std::cin >> arr2[i];
        }

        std::vector<int> merged_arr;
        merged_arr.reserve(n1 + n2);
        merged_arr.insert(merged_arr.end(), arr1.begin(), arr1.end());
        merged_arr.insert(merged_arr.end(), arr2.begin(), arr2.end());

        std::sort(merged_arr.begin(), merged_arr.end());

        for (int i = 0; i < merged_arr.size(); ++i) {
            std::cout << merged_arr[i] << (i == merged_arr.size() - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}

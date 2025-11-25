#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

int main() {
    int t;
    std::cin >> t;
    for (int cs = 1; cs <= t; ++cs) {
        int a, b, c;
        std::cin >> a >> b >> c;
        std::vector<int> nums = {a, b, c};
        std::sort(nums.begin(), nums.end());
        printf("Case %d: %d %d %d\n", cs, nums[0], nums[1], nums[2]);
    }
    return 0;
}

#include <vector>
using namespace std;

class Solution {
 public:
  int findKthPositive(vector<int>& arr, int k) {
    if (arr[0] > k) return k;
    int low = 0, high = arr.size() - 1;
    int ans = 0;
    while (low <= high) {
      int mid = (low + high) / 2;
      int skipped = arr[mid] - mid - 1;
      if (skipped < k) {
        ans = mid;
        low = mid + 1;
      } else
        high = mid - 1;
    }
    return k + ans + 1;
  }
};

#include <gtest/gtest.h>

TEST(KthMissingPositiveNumber, Test1) {
  Solution solution;
  vector<int> arr = {2, 3, 4, 7, 11};
  int k = 5;
  int expected = 9;
  int actual = solution.findKthPositive(arr, k);
  ASSERT_EQ(actual, expected);
}

TEST(KthMissingPositiveNumber, Test2) {
  Solution solution;
  vector<int> arr = {1, 2, 3, 4};
  int k = 2;
  int expected = 6;
  int actual = solution.findKthPositive(arr, k);
  ASSERT_EQ(actual, expected);
}
TEST(KthMissingPositiveNumber, Test3) {
  Solution solution;
  vector<int> arr = {1, 2, 3, 4};
  int k = 3;
  int expected = 7;
  int actual = solution.findKthPositive(arr, k);
  ASSERT_EQ(actual, expected);
}
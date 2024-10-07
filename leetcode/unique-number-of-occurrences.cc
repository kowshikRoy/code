#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool uniqueOccurrences(vector<int> &arr) {
    map<int, int> mp;
    set<int> s;
    for (auto a : arr) mp[a]++;
    for (auto [k, v] : mp) s.insert(v);
    return s.size() == mp.size();
  }
};

#include <gtest/gtest.h>

TEST(UniqueNumberOfOccurrences, Test1) {
  Solution solution;
  vector<int> arr = {1, 2, 2, 1, 1, 3};
  ASSERT_TRUE(solution.uniqueOccurrences(arr));
}

TEST(UniqueNumberOfOccurrences, Test2) {
  Solution solution;
  vector<int> arr = {1, 2};
  ASSERT_FALSE(solution.uniqueOccurrences(arr));
}

TEST(UniqueNumberOfOccurrences, Test3) {
  Solution solution;
  vector<int> arr = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
  ASSERT_TRUE(solution.uniqueOccurrences(arr));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
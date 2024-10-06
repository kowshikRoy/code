#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    for (int i = 0; i < citations.size(); i++) {
      if (citations[i] >= citations.size() - i) {
        return citations.size() - i;
      }
    }
    return 0;
  }
};

#include <gtest/gtest.h>

TEST(HIndexTest, Test1) {
  Solution solution;
  std::vector<int> citations = {3, 0, 6, 1, 5};
  ASSERT_EQ(solution.hIndex(citations), 3);
}

TEST(HIndexTest, Test2) {
  Solution solution;
  std::vector<int> citations = {1, 3, 1};
  ASSERT_EQ(solution.hIndex(citations), 1);
}

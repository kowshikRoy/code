#include <vector>
using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int>>& g) {
    if (g.empty()) return;
    int n = g.size(), m = g[0].size();
    int zero_first_row = false, zero_first_col = false;

    for (int j = 0; j < m; j++)
      if (g[0][j] == 0) zero_first_row = true;
    for (int i = 0; i < n; i++)
      if (g[i][0] == 0) zero_first_col = true;
    for (int i = 1; i < n; i++)
      for (int j = 1; j < m; j++)
        if (g[i][j] == 0) {
          g[i][0] = 0;
          g[0][j] = 0;
        }

    for (int i = 1; i < n; i++)
      for (int j = 1; j < m; j++)
        if (g[i][0] == 0 || g[0][j] == 0) g[i][j] = 0;
    if (zero_first_row)
      for (int j = 0; j < m; j++) g[0][j] = 0;
    if (zero_first_col)
      for (int i = 0; i < n; i++) g[i][0] = 0;
  }
};

#include <gtest/gtest.h>

TEST(SetMatrixZeroesTest, Test1) {
  Solution solution;
  vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  vector<vector<int>> expected = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
  solution.setZeroes(matrix);
  ASSERT_EQ(matrix, expected);
}

TEST(SetMatrixZeroesTest, Test2) {
  Solution solution;
  vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  vector<vector<int>> expected = {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
  solution.setZeroes(matrix);
}
TEST(SetMatrixZeroesTest, Test3) {
  Solution solution;
  vector<vector<int>> matrix = {
      {1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0}};
  vector<vector<int>> expected = {
      {0, 0, 3, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  solution.setZeroes(matrix);
  ASSERT_EQ(matrix, expected);
}

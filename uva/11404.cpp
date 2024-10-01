/**
 * Author: Repon Kumar Roy
 * Date: 2023-02-02
 * Task: 11404
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string str;
  while (cin >> str) {
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n));
    vector<string> ss;
    for (int i = 0; i < n; i++)
      dp[i][i] = ss.size(), ss.emplace_back(str.substr(i, 1));
    for (int i = 0; i < n - 1; i++) {
      if (str[i] == str[i + 1]) {
        dp[i][i + 1] = ss.size();
        ss.emplace_back(str.substr(i, 2));
      } else {
        if (str[i] < str[i + 1])
          dp[i][i + 1] = dp[i][i];
        else
          dp[i][i + 1] = dp[i + 1][i + 1];
      }
    }

    for (int len = 3; len <= n; len++) {
      for (int i = 0, j = i + len - 1; j < n; i++, j++) {
        if (str[i] == str[j]) {
          dp[i][j] = ss.size();
          string news =
              str.substr(i, 1) + ss[dp[i + 1][j - 1]] + str.substr(j, 1);
          ss.emplace_back(news);
        }

        else {
          auto &a = ss[dp[i + 1][j]], &b = ss[dp[i][j - 1]];

          if (a.length() == b.length()) {
            if (a < b)
              dp[i][j] = dp[i + 1][j];
            else
              dp[i][j] = dp[i][j - 1];
          } else
            dp[i][j] = a.length() > b.length() ? dp[i + 1][j] : dp[i][j - 1];
        }
      }
    }
    cout << ss[dp[0][n - 1]] << endl;
  }
}

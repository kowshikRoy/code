/**
 * Author: Repon Kumar Roy
 * Date: 2023-02-02
 * Task: 11404a
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string str;
  while (cin >> str) {
    int n = str.length();
    vector<vector<int>> nxt(n, vector<int>(26, n));
    for (int i = n - 1; i >= 0; i--) {
      if (i + 1 < n) nxt[i] = nxt[i + 1];
      nxt[i][str[i] - 'a'] = i;
    }
    vector<vector<int>> lst(n, vector<int>(26, -1));
    for (int i = 0; i < n; i++) {
      if (i > 0) lst[i] = lst[i - 1];
      lst[i][str[i] - 'a'] = i;
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int i = 0; i < n - 1; i++) dp[i][i + 1] = str[i] == str[i + 1] ? 2 : 1;
    for (int len = 3; len <= n; len++) {
      for (int i = 0, j = i + len - 1; j < n; i++, j++) {
        if (str[i] == str[j])
          dp[i][j] = 2 + dp[i + 1][j - 1];
        else
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
      }
    }
    int maxLen = dp[0][n - 1], L = 0, R = n - 1;
    string ans;
    while (maxLen >= 2) {
      for (int c = 0; c < 26; c++) {
        int l = nxt[L][c], r = lst[R][c];
        if (l < r && dp[l][r] == maxLen) {
          ans.push_back(c + 'a');
          L = l + 1;
          R = r - 1;
          maxLen -= 2;
          break;
        }
      }
    }
    string cpy = ans;
    reverse(cpy.begin(), cpy.end());

    if (maxLen) {
      char middle = 'z';
      for (int i = L; i <= R; i++) {
        if (str[i] < middle) middle = str[i];
      }
      cout << ans + middle + cpy << endl;
    } else
      cout << ans + cpy << endl;
  }

  return 0;
}

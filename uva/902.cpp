/**
 * Author: Repon Kumar Roy
 * Date: 2023-02-06
 * Task: 902
 */

#include <algorithm>
#include <cassert>
#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int n;
  string s;
  while (cin >> n >> s) {
    map<string, int> cnt;
    for (int i = 0; i + n <= s.size(); i++) { cnt[s.substr(i, n)]++; }
    int iMax = 0;
    string ans;
    for (auto e : cnt) {
      if (e.second > iMax) {
        iMax = e.second;
        ans = e.first;
      }
    }
    cout << ans << endl;
  }
}

/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-28
 * Task: 10663
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

const int N = 500501;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<bool> isPow(N);
  for (int i = 2; i * i <= N; i++) {
    int t = i;
    while (t * i < N) isPow[t * i] = 1, t *= i;
  }
  vector<vector<pair<int, int>>> q(1001, vector<pair<int, int>>());
  int n = 0;
  while (cin >> l >> r) q[l].push_back({r, n++});
  vector<vector<int>> Ans(n);
  REP(i, 1001) sort(q[i].begin(), q[i].end());
  REP(i, 1001) {
    auto &Q = q[i];
    if (Q.size() == 0) continue;
    int L = 0;
    vector<int> inList;
    for (int b = i; L < Q.size(); b++) {
      for (auto x : inList) if(x + 





    return 0;
    }

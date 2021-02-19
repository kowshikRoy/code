#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;

int N, M vector<int> G[maxn];
long long dp[N];

void func(long long &a, long long b) { a = (a * b) % M; }
void dfs(int u, int p) {
    dp[u] = 1;
    for (auto v : G[u])
        if (v != p) {
            dfs(v, u);
            mul(dp[u], 1 + dp[v]);
        }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, -1);
  for(int i = 1; i <= n; i++
  return 0;
}

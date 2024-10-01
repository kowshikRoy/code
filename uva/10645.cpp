/**
 * Author: Repon Kumar Roy
 * Date: 2023-02-05
 * Task: 10645
 */

#include <algorithm>
#include <cassert>
#include <climits>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = INT_MAX / 4;

int K;
int N;
int M;
int c[55], v[55];
int dp[22][105][55][2];

pair<int, bool> choice[22][104][55][2];

int main() {
  while (cin >> K >> N >> M) {
    if (K == 0 && N == 0 && M == 0) break;

    for (int i = 0; i < N; i++) {
      cin >> c[i] >> v[i];
      v[i] *= 2;
    }
    // dp(i,total_cost, dish, same) = max_value
    for (int cost = 0; cost <= M; cost++) {
      for (int dish = 0; dish < N; dish++) {
        for (int s = 0; s < 2; s++) dp[1][cost][dish][s] = -INF;
      }
    }

    for (int dish = 0; dish < N; dish++) {
      if (c[dish] <= M) dp[1][c[dish]][dish][0] = v[dish];
    }
    for (int i = 2; i <= K; i++) {
      for (int cost = 0; cost <= M; cost++) {
        for (int dish = 0; dish < N; dish++) {
          dp[i][cost][dish][0] = -INF;
          dp[i][cost][dish][1] = -INF;
          if (cost < c[dish]) continue;

          int a = -INF, b = -INF;
          pair<int, int> pa, pb;
          for (int pre_dish = 0; pre_dish < N; pre_dish++) {
            if (dish == pre_dish) {
              // if isSame = 1, no value added
              int tb = dp[i - 1][cost - c[dish]][pre_dish][1];
              if (tb > b) {
                b = tb;
                pb = {pre_dish, 1};
              }
              // if isSame = 0, v[dish]/2 added
              tb = v[dish] / 2 + dp[i - 1][cost - c[dish]][pre_dish][0];
              if (tb > b) {
                b = tb;
                pb = {pre_dish, 0};
              }

            } else {
              int ta = v[dish] + dp[i - 1][cost - c[dish]][pre_dish][0];
              if (ta > a) {
                a = ta;
                pa = {pre_dish, 0};
              }
              ta = v[dish] + dp[i - 1][cost - c[dish]][pre_dish][1];
              if (ta > a) {
                a = ta;
                pa = {pre_dish, 1};
              }
            }
          }
          dp[i][cost][dish][0] = a < 0 ? -INF : a;
          dp[i][cost][dish][1] = b < 0 ? -INF : b;
          choice[i][cost][dish][0] = pa;
          choice[i][cost][dish][1] = pb;
        }
      }
    }

    vector<int> dishes;

    int Dish, IsSame, Cost;
    int ans = -INF;
    for (int cost = 0; cost <= M; cost++) {
      for (int dish = 0; dish < N; dish++) {
        for (int isSame = 0; isSame < 2; isSame++) {
          if (dp[K][cost][dish][isSame] > ans) {
            ans = dp[K][cost][dish][isSame];
            Cost = cost;
            Dish = dish;
            IsSame = isSame;
          }
        }
      }
    }

    if (ans <= 0) {
      printf("0.0\n\n");
      continue;
    }
    dishes.push_back(Dish);
    for (int i = K - 1; i > 0; i--) {
      auto nxt = choice[i + 1][Cost][Dish][IsSame];
      Cost = Cost - c[Dish];
      Dish = nxt.first;
      dishes.push_back(Dish);
      IsSame = nxt.second;
    }

    printf("%.1lf\n", ans / 2.0);
    reverse(dishes.begin(), dishes.end());
    for (int i = 0; i < (int)dishes.size(); i++) {
      printf("%d%c", dishes[i] + 1, i == (int)dishes.size() - 1 ? '\n' : ' ');
    }
  }
}

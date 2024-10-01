/**
 * Author: Repon Kumar Roy
 * Date: 2023-02-09
 * Task: 1609
 */

#include <algorithm>
#include <cassert>
#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << "]" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H; if(sizeof...(T)) cerr << ", "; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


int n;
char g[1024][1025];
void solve() {
  for(int i = 0; i < n; i ++) scanf("%s", g[i]);
  vector<int> alive;
  vector<int> paired(n,0);
  for(int i = 1; i < n; i ++) alive.push_back(i);
  for(int level = 1; level < n - 1; level *=2) {
    vector<int> low, high;
    for(auto x: alive) {
      if(g[0][x] == '1') low.push_back(x);
      else high.push_back(x);
      paired[x] = false;
    }
    assert(low.size() > high.size());
    alive.clear();
    for(auto x: high) {
      if(paired[x]) continue;
      for(auto y: low) {
        if(paired[y]) continue;
        if(g[y][x] == '1') {
          alive.push_back(y);
          paired[x] = true;
          paired[y] = true;
          printf("%d %d\n", x + 1, y + 1);
          break;
        }
      }
      if(!paired[x]) {
        for(auto nx: high) {
          if(nx !=x && paired[nx] == 0) {
            paired[nx] = true;
            paired[x] = true;
            if(g[x][nx] == '1') alive.push_back(x);
            else alive.push_back(nx);
            printf("%d %d\n", x + 1, nx + 1);
            break;
          }
        }
      }
    }
    int prev_y = -1;
    for(auto y: low) {
      if(paired[y]) continue;
      if(prev_y != -1) {
        printf("%d %d\n", y + 1, prev_y +1 );
        alive.push_back(g[y][prev_y] == '1' ? y : prev_y);
        prev_y = -1;
      }
      else {
        prev_y = y;
      }
    }
    assert(prev_y >= 0 && g[0][prev_y] == '1');
    printf("%d %d\n", 1, prev_y + 1);
  }

}

int main() {
  while(scanf("%d",&n) == 1) solve();

  return 0;
}

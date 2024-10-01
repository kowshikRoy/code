/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-28
 * Task: 12345
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

#include <ext/pb_ds/assoc_container.hpp>  // Common file
#include <ext/pb_ds/tree_policy.hpp>  // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    OS;

const int N = 50005;

vector<int> A;
vector<int> B;
OS T[4 * N];
void build(int n, int b, int e) {
  if (b == e) {
    T[n].insert({B[b], b});
    return;
  }
  int mid = (b + e) / 2;
  build(2 * n, b, mid);
  build(2 * n + 1, mid + 1, e);
  for (int i = b; i <= e; i++) T[n].insert({B[i], i});
}

void update(int n, int b, int e, int pos, int prv, int now) {
  T[n].erase({prv, pos});
  T[n].insert({now, pos});
  if (b == e) return;
  int mid = (b + e) / 2;
  if (pos <= mid)
    update(2 * n, b, mid, pos, prv, now);
  else
    update(2 * n + 1, mid + 1, e, pos, prv, now);
}

int query(int n, int b, int e, int i, int j, int v) {
  if (b > j || e < i) return 0;
  if (b >= i && e <= j) { return T[n].order_of_key({v, -1}); }

  int mid = (b + e) / 2;
  return query(2 * n, b, mid, i, j, v) + query(2 * n + 1, mid + 1, e, i, j, v);
}

set<int> pos[1000006];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  A.resize(n);
  B.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    if (pos[A[i]].size())
      B[i] = *pos[A[i]].rbegin();
    else
      B[i] = -1;
    pos[A[i]].insert(i);
  }
  build(1, 0, n - 1);
  while (m--) {
    char q;
    cin >> q;
    if (q == 'M') {
      int x, y;
      cin >> x >> y;
      auto &s = pos[A[x]];
      auto ptr = s.find(x);
      ptr++;
      if (ptr != s.end()) {
        int indx = *ptr;
        update(1, 0, n - 1, indx, B[indx], B[x]);
        B[indx] = B[x];
      }
      s.erase(x);
      auto &t = pos[y];
      t.insert(x);
      ptr = t.find(x);
      ptr++;
      if (ptr != t.end()) {
        int indx = *ptr;
        update(1, 0, n - 1, indx, B[indx], x);
        B[indx] = x;
      }
      ptr--;
      if (ptr != t.begin()) {
        ptr--;
        update(1, 0, n - 1, x, B[x], *ptr);
        B[x] = *ptr;
      } else {
        update(1, 0, n - 1, x, B[x], -1);
        B[x] = -1;
      }
      A[x] = y;
    } else {
      int l, r;
      cin >> l >> r;
      cout << query(1, 0, n - 1, l, r - 1, l) << endl;
    }
  }

  return 0;
}

/**
 * Author: Repon Kumar Roy
 * Date: 2023-02-04
 * Task: 11297
 */

#include <cassert>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

#define PII pair<int, int>

int N;
PII t[2505][2505];

int p[505][505];
PII merge(PII a, PII b) {
  return {max(a.first, b.first), min(a.second, b.second)};
};

void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
  if (ly == ry) {
    if (lx == rx)
      t[vx][vy] = {p[lx][ly], p[lx][ly]};
    else
      t[vx][vy] = merge(t[vx * 2][vy], t[vx * 2 + 1][vy]);
  } else {
    int mid = (ly + ry) / 2;
    build_y(vx, lx, rx, 2 * vy, ly, mid);
    build_y(vx, lx, rx, 2 * vy + 1, mid + 1, ry);
    t[vx][vy] = merge(t[vx][2 * vy], t[vx][2 * vy + 1]);
  }
}

void build_x(int vx, int lx, int rx) {
  if (lx != rx) {
    int mid = (lx + rx) / 2;
    build_x(vx * 2, lx, mid);
    build_x(vx * 2 + 1, mid + 1, rx);
  }
  build_y(vx, lx, rx, 1, 0, N - 1);
}

void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y,
              int v) {
  if (ly == ry) {
    if (lx == rx)
      t[vx][vy] = {v, v};
    else
      t[vx][vy] = merge(t[2 * vx][vy], t[2 * vx + 1][vy]);
  } else {
    int mid = (ly + ry) / 2;
    if (y <= mid)
      update_y(vx, lx, rx, vy * 2, ly, mid, x, y, v);
    else
      update_y(vx, lx, rx, vy * 2 + 1, mid + 1, ry, x, y, v);
    t[vx][vy] = merge(t[vx][vy * 2], t[vx][vy * 2 + 1]);
  }
}

void update_x(int vx, int lx, int rx, int x, int y, int v) {
  if (lx != rx) {
    int mid = (lx + rx) / 2;
    if (x <= mid)
      update_x(vx * 2, lx, mid, x, y, v);
    else
      update_x(vx * 2 + 1, mid + 1, rx, x, y, v);
  }
  update_y(vx, lx, rx, 1, 0, N - 1, x, y, v);
}

PII query_y(int vx, int vy, int ly, int ry, int y1, int y2) {
  if (y1 > y2) return {-1, INT_MAX};
  if (ly == y1 && ry == y2) { return t[vx][vy]; }
  int mid = (ly + ry) / 2;
  return merge(query_y(vx, vy * 2, ly, mid, y1, min(y2, mid)),
               query_y(vx, vy * 2 + 1, mid + 1, ry, max(y1, mid + 1), y2));
}

PII query_x(int vx, int lx, int rx, int x1, int x2, int y1, int y2) {
  if (x1 > x2) return {-1, INT_MAX};
  if (lx == x1 && rx == x2) return query_y(vx, 1, 0, N - 1, y1, y2);

  int mid = (lx + rx) / 2;
  return merge(query_x(2 * vx, lx, mid, x1, min(x2, mid), y1, y2),
               query_x(2 * vx + 1, mid + 1, rx, max(x1, mid + 1), x2, y1, y2));
}

int main() {
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) scanf("%d", &p[i][j]);
  }
  build_x(1, 0, N - 1);
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    char ch;
    scanf(" %c ", &ch);
    if (ch == 'q') {
      int x1, x2, y1, y2;
      scanf("%d %d %d %d ", &x1, &y1, &x2, &y2);
      x1--, x2--, y1--, y2--;
      auto out = query_x(1, 0, N - 1, x1, x2, y1, y2);
      printf("%d %d\n", out.first, out.second);

    } else {
      int x, y, v;
      scanf("%d %d %d ", &x, &y, &v);
      x--, y--;
      update_x(1, 0, N - 1, x, y, v);
    }
  }
}

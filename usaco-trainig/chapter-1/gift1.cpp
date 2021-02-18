/*
ID: newcode2
PROG: gift1
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("gift1.in", "r", stdin);
  freopen("gift1.out", "w", stdout);

  int n;
  string p[11];
  map<string,int> M;
  cin >> n;
  for(int i = 0; i < n; i ++) cin >> p[i];
  for(int i = 0; i < n; i ++) {
      string cur;
      int money, friends;
      cin >> cur;
      cin >> money >> friends;
      if(friends == 0) continue;
      M[cur] -= (money - money % friends);
      for(int j = 0; j < friends; j ++)  {
          string f;
          cin >> f;
          M[f] += money / friends;
      }
  }
  for(int i = 0; i < n; i ++) {
      cout << p[i] << " " << M[p[i]] << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;

int cursor;
unordered_map<string, int> dict;
int get(string s) {
  if (dict.count(s)) return dict[s];
  return dict[s] = ++cursor;
}
vector<int> parse(string str) {
  vector<int> ret;
  string cur;
  for (int i = 0; i < (int)str.size(); i++) {
    if (str[i] == ',') {
      ret.push_back(get(cur));
      cur.clear();
    } else
      cur.push_back(str[i]);
  }
  ret.push_back(get(cur));
  return ret;
}
int main() {
  int n, m;
  string str;
  while (scanf("%d %d", &n, &m) == 2) {
    vector<vector<int>> table(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      while (getline(cin, str) && str.size() == 0)
        ;
      table[i] = parse(str);
    }
    bool isPNF = true;
    int r1, r2, c1, c2;
    for (int i = 0; i < m; i++) {
      for (int j = i + 1; j < m; j++) {
        map<pair<int, int>, int> S;
        for (int k = 0; k < n; k++) {
          auto a = make_pair(table[k][i], table[k][j]);
          if (S.find(a) != S.end()) {
            isPNF = false;
            r1 = S[a];
            r2 = k;
            c1 = i;
            c2 = j;
            goto print;
          }
          S[a] = k;
        }
      }
    }
  print:
    if (isPNF)
      printf("YES\n");
    else { printf("NO\n%d %d\n%d %d\n", r1 + 1, r2 + 1, c1 + 1, c2 + 1); }
    dict.clear();
  }
}

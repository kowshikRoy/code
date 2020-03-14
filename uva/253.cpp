#include <cstdio>
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;
string s1, s2;

string L(string s) {
  string r(s);
  r[1] = s[1];
  r[6] = s[6];
  r[2] = s[3];
  r[3] = s[5];
  r[4] = s[2];
  r[5] = s[4];
  return r;
}

string U(string s) {
  string r(s);
  r[3] = s[3];
  r[4] = s[4];
  r[1] = s[2];
  r[2] = s[6];
  r[5] = s[1];
  r[6] = s[5];
  return r;
}

int main() {
  string s;
  while (cin >> s) {
    s1 = 'o' + s.substr(0, 6);
    s2 = 'o' + s.substr(6);

    unordered_set<string> Visited;

    bool flag = 0;
    queue<string> q;
    q.push(s1);
    while (!q.empty()) {
      s = q.front();
      q.pop();
      Visited.insert(s);

      if (s == s2) {
        flag = true;
        break;
      }
      auto x = L(s);
      if (Visited.count(x) == 0)
        q.push(x);
      x = U(s);
      if (Visited.count(x) == 0)
        q.push(x);
    }

    printf("%s\n", flag ? "TRUE" : "FALSE");
  }
}

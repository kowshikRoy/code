#include <bits/stdc++.h>
using namespace std;

int main() {
  char str[104];
  while (gets(str)) {
    string s(str);
    if (s.length() == 0)
      continue;
    bool window = true;
    int pivot = 1 << 20;
    for (int k = 1; k <= s.length(); k++) {
      unordered_set<string> M;
      for (int i = 0; i + k - 1 < s.length(); i++) {
        string t = s.substr(i, k);
        M.insert(t);
        if (M.size() > k + 1) {
          window = false;
          pivot = min(pivot, i + k - 1);
          break;
        }
      }
    }
    if (window)
      printf("YES\n");
    else
      printf("NO:%d\n", pivot + 1);
  }
}

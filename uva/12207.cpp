#include <bits/stdc++.h>
using namespace std;

int main() {
  int P, C, cs = 0;
  char type[1005];
  int x[1005];
  while (scanf("%d %d", &P, &C) == 2) {
    if (P == 0 && C == 0)
      break;
    printf("Case %d:\n", ++cs);
    set<int> s;
    deque<int> dq;
    for (int i = 1; i <= min(C, P); i++)
      s.insert(i), dq.push_back(i);
    for (int i = 0; i < C; i++) {
      cin >> type[i];
      if (type[i] == 'E') {
        cin >> x[i];
        if (s.count(x[i]) == 0) {
          s.insert(x[i]);
          dq.push_back(x[i]);
        }
      }
    }
    for (int i = 0; i < C; i++) {
      if (type[i] == 'N') {
        int f = dq.front();
        cout << f << endl;
        dq.pop_front();
        dq.push_back(f);
      } else {
        auto it = find(dq.begin(), dq.end(), x[i]);
        if (it != dq.end())
          dq.erase(it);
        dq.push_front(x[i]);
      }
      /* for(auto t: dq) cout << t << " "; cout << endl; */
    }
  }
}

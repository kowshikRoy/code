#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}

void dbg_out() { cerr << "]" << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << H;
  if (sizeof...(T)) cerr << ", ";
  dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...)                                                     \
  cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", \
      dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-30
 * Task: 10142
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> name(n + 1);
    for (int i = 1; i <= n; i++) {
      getline(cin, name[i]);
      if (name[i].length() == 0) {
        i--;
        continue;
      }
    }

    vector<vector<int>> votes;
    int tot = 0;
    string inp;
    while (getline(cin, inp)) {
      if (inp.length() == 0) break;
      istringstream iss(inp);
      vector<int> v;
      REP(i, n) {
        int can;
        iss >> can;
        v.push_back(can);
      }
      votes.push_back(v);
      tot++;
    }
    vector<int> ele(n + 1, 0);
    int pivot = -1;

    while (pivot == -1) {
      vector<int> cnt(n + 1, 0);
      for (auto x : votes) {
        for (auto y : x) {
          if (ele[y]) continue;
          cnt[y]++;
          break;
        }
      }
      int minVote = INT_MAX;
      int pivot = -1;
      set<int> all;
      for (int i = 1; i <= n; i++) {
        if (ele[i]) continue;
        minVote = min(minVote, cnt[i]);
        if (cnt[i] * 2 > tot) {
          pivot = i;
          break;
        }
        all.insert(cnt[i]);
      }
      if (pivot != -1) {
        cout << name[pivot] << endl;
        break;
      }
      if (all.size() == 1) {
        for (int i = 1; i <= n; i++)
          if (!ele[i]) cout << name[i] << endl;
        break;
      }
      for (int i = 1; i <= n; i++) {
        if (cnt[i] == minVote) { ele[i] = true; }
      }
    }
    if (t) cout << endl;
  }

  return 0;
}

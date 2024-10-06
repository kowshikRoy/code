/**
 * Author: Repon Kumar Roy
 * Date: 2021-09-04
 * Task: 1044
 */

#include <bits/stdc++.h>
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

using namespace std;

class Solution {
 private:
  int B = 31, M = 1e9 + 7;
  vector<long long> H;
  vector<long long> POW;

 public:
  void make_hash(string &s) {
    int n = (int)s.size();
    H.resize(n);
    POW.resize(n);
    POW[0] = 1;
    for (int i = 1; i < n; i++) POW[i] = (POW[i - 1] * B) % M;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      H[i] = sum = (sum * B + s[i] - 'a' + 1) % M;
    }
    dbg(H);
    dbg(POW);
  }

  unsigned long long hash(int i, int j) {
    assert(i <= j);
    return ((H[j] - (i > 0 ? H[i - 1] * POW[j - i + 1] : 0)) % M + M) % M;
  }

  string longestDupSubstring(string s) {
    make_hash(s);
    cout << hash(0, 2) << " " << hash(2, 4) << endl;
    const int n = (int)s.size();
    int low = 1, high = n - 1, ans = 0, index = -1;

    auto can = [&](int len) -> int {
      unordered_set<unsigned long long> s;
      cout << "len: " << len << endl;
      for (int i = 0, j = len - 1; j < n; i++, j++) {
        auto x = hash(i, j);
        cout << i << " " << j << " " << x << endl;
        if (s.count(x)) {
          return i;
        }
        s.insert(x);
      }
      return -1;
    };

    while (low <= high) {
      int mid = low + (high - low) / 2;
      int v = can(mid);
      if (v >= 0)
        ans = mid, index = v, low = mid + 1;
      else
        high = mid - 1;
    }
    if (ans == 0) return "";
    return s.substr(index, ans);
  }
};
int main() {
  string s = "banana";
  cout << Solution().longestDupSubstring(s) << endl;
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

long long n, K;
struct Node {
  ll to, sum, iMin, len;
};
vector<Node> vec;

vector<Node> mul(vector<Node> a, vector<Node> b) {
  vector<Node> R(n);
  for (int i = 0; i < n; i++) {
    R[i].len = a[i].len + b[i].len;
    int x = a[i].to;
    R[i].to = b[x].to;
    R[i].sum = a[i].sum + b[x].sum;
    R[i].iMin = min(a[i].iMin, b[x].iMin);
  }
  return R;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> K;
  vec.resize(n);
  for (int i = 0; i < n; i++)
    cin >> vec[i].to;
  for (int i = 0; i < n; i++)
    cin >> vec[i].sum, vec[i].iMin = vec[i].sum, vec[i].len = 1;

  auto ans = vec;
  auto modu = vec;
  K--;
  while (K) {
    if (K & 1)
      ans = mul(ans, modu);
    K /= 2;
    modu = mul(modu, modu);
  }
  for (auto x : ans) {
    cout << x.sum << " " << x.iMin << endl;
  }

  return 0;
}

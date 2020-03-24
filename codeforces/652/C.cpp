#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
int p[N], pos[N];
vector<int> g[N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> p[i], pos[p[i]] = i;
	for(int i = 0; i < m ; i ++) {
		int x,y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	int rightMost = 0;
	long long ans = 0;
	for(int i = 1; i <= n; i ++) {
		int v = p[i];
		for(auto x: g[v]) {
			if(pos[x] < i) {
				rightMost = max(rightMost, pos[x]);
			}
		}
		ans += (i - rightMost);
	}
	cout << ans << endl;
	return 0;

}

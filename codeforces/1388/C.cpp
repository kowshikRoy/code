#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n, m;
int pop[N], h[N], sub[N];
vector<int> g[N];
void dfs(int u, int p) {
	sub[u] = pop[u];
	for (auto v : g[u])
		if (v != p) {
			dfs(v, u);
			sub[u] += sub[v];
		}
}

bool trv(int u, int p, int good, int bad) {
	cout <<"ROOT:" <<  u << " " << good << " " << bad << endl;
	int sum = 0;
	for (auto v : g[u])
		if (v != p) {
			int cur = h[v];
			int tot = sub[v];
			cout << v << " " << cur << " " << tot << endl;
			if ((cur + tot) % 2)
				return false;
			int good = (tot + cur) / 2, bad = (tot - cur) / 2;
			sum += good;
		}

	cout << sum << " " << good << endl;
	if (sum > good)
		return false;
	bool ret = true;
	for (auto v : g[u])
		if (v != p) {
			int cur = h[v];
			int tot = sub[v];
			if (cur % 2 != tot % 2)
				return false;
			int good = (tot + cur) / 2, bad = (tot - cur) / 2;
			ret &= trv(v, u, good, bad);
		}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			g[i].clear();
		for (int i = 1; i <= n; i++)
			cin >> pop[i];
		for (int i = 1; i <= n; i++)
			cin >> h[i];
		for (int i = 1; i < n; i++) {
			int x, y;
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(1, -1);
		if ((h[1] + sub[1])%2) {
			cout << "NO\n";
			continue;
		}
		int good = (h[1] + sub[1]) / 2, bad = (sub[1] - h[1]) / 2;
		if (good > m || bad < 0) {
			cout << "NO\n";
			continue;
		}
		printf("%s\n", trv(1, -1, good, bad) ? "YES" : "NO");
	}

	return 0;
}

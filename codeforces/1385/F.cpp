#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> g[N];
int n, k;

int par[N], isLeaf[N], deg[N];

int dfs(int u, int p) {
	int ret = 0;
	for (auto v : g[u])
		if (v != p) {
			par[v] = u;
			ret += dfs(v, u);
		}

	bool flag = true;
	int cnt = 0;

	for (auto v : g[u])
		if (v != p) {
			if (isLeaf[v])
				cnt++;
			else
				flag = false;
		}

	ret += cnt / k;
	if (flag && cnt % k == 0)
		isLeaf[u] = true;
	else isLeaf[u] = false;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
			deg[u]++;
			deg[v]++;
		}
		if (n == 2) {
			printf("%d\n", k == 1 ? 1 : 0);
			continue;
		}
		else {
			int root = -1;
			for (int i = 1; i <= n; i++) {
				if (deg[i] >= 2) {
					root = i;
					break;
				}
			}
			cout << dfs(root, -1) << endl;
		}
		for (int i = 1; i <= n; i++)
			g[i].clear(), deg[i] = 0, par[i] = -1, isLeaf[i] = false;
	}

	return 0;
}

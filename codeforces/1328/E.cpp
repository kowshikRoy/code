#include <bits/stdc++.h>
using namespace std;

const int LG = 20;
const int N = 2e5 + 5;
int P[N][20];
int lev[N];
vector<int> G[N];
int n, m;

int LCA(int u, int v) {
	if (lev[u] > lev[v])
		swap(u, v);
	int d = lev[v] - lev[u];
	for (int i = LG - 1; i >= 0; i--) {
		if (d & (1 << i)) {
			v = P[v][i];
		}
	}

	if (u == v)
		return u;
	for (int i = LG - 1; i >= 0; i--) {
		if (P[u][i] != P[v][i]) {
			u = P[u][i];
			v = P[v][i];
		}
	}
	return P[v][0];
}
void dfs(int u, int p) {
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (v == p)
			continue;
		lev[v] = 1 + lev[u];
		P[v][0] = u;
		dfs(v, u);
	}
}
void process() {
	memset(P, -1, sizeof(P));
	dfs(1, -1);
	for (int i = 1; i < LG; i++) {
		for (int j = 1; j <= n; j++)
			if (P[j][i - 1] != -1)
				P[j][i] = P[P[j][i - 1]][i - 1];
	}
}

bool solve(int pivot, vector<int> &nodes) {
	for (auto x : nodes) {
		int par = LCA(pivot, x);
		if (x == par || P[x][0] == par)
			continue;
		return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {

		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	process();
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		vector<int> nodes;
		int pivot = -1;
		for (int i = 0; i < k; i++) {
			int x;
			cin >> x;
			nodes.push_back(x);
			if (pivot == -1 || lev[pivot] < lev[x]) {
				pivot = x;
			}
		}
		if (solve(pivot, nodes) ||
				(P[pivot][0] != -1 && solve(P[pivot][0], nodes))) {
			cout << "YES" << endl;
		} else
			cout << "NO" << endl;
	}
	return 0;
}

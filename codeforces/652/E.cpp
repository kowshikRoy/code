#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
#define FO(i, a, b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;
struct bcc {
	vector<vector<int>> u;
	vector<int> bc, lo, ind, SZ;
	vector<vector<int>> G;
	int T, m, n;

	void init(int n_) {
		n = n_;
		m = 0;
		T = 0;
		u.clear();
		u.resize(n);
		G.clear();
		G.resize(n);
		bc.assign(n, -1);
		lo.assign(n, -1);
		SZ.assign(n, 0);
		ind.assign(n, -1);
	}

	void adde(int i, int j) {
		u[i].push_back(j);
		u[j].push_back(i);
	}

	vector<int> stk;
	void go(int i, int p) {
		ind[i] = lo[i] = ++T;
		stk.push_back(i);

		for (int j : u[i])
			if (j != p) {
				if (ind[j] == -1) {
					go(j, i);
					lo[i] = min(lo[i], lo[j]);
				} else {
					lo[i] = min(lo[i], ind[j]);
				}
			} else
				p = -1;

		if (ind[i] == lo[i]) {
			int t;
			do {
				t = stk.back();
				stk.pop_back();
				bc[t] = m;
			} while (t != i);
			m++;
		}
	}

	void dobcc() { FO(i, 0, n) if (ind[i] == -1) go(i, -1); }
} B;
int u[N], v[N], c[N];
vector<pair<int, int>> T[N];
int good[N];
int h[N];
void dfs(int u, int p, bool flag) {
	flag |= good[u];
	h[u] = flag;
	for (auto v : T[u]) {
		if (v.first != p) {
			 dfs(v.first, u,flag | v.second);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	B.init(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> u[i] >> v[i] >> c[i];
		u[i]--, v[i]--;
		B.adde(u[i], v[i]);
	}
	B.dobcc();
	int a, b;
	cin >> a >> b;
	a--, b--;
	int X = B.bc[a], Y = B.bc[b];

	for (int i = 0; i < m; i++) {
		int x = B.bc[u[i]], y = B.bc[v[i]];
		if (x != y) {
			T[x].push_back(make_pair(y, c[i]));
			T[y].push_back(make_pair(x, c[i]));
		} else {
			if (c[i] == 1)
				good[x] = 1;
		}
	}
	dfs(X, -1,  0);
	if(h[Y])
		cout << "YES";
	else
		cout << "NO";
}


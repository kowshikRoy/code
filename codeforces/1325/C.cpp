#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int> g[N];
int col[N];
int node[N];
int deg[N];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n ; i ++) {
		node[i] = i + 1;
	}
	for(int i = 0; i < n -1 ; i ++) {
		int a,b;
		cin >> a >> b;
		deg[a] ++;
		deg[b] ++;
		g[a].push_back(i);
		g[b].push_back(i);
	}
	sort(node, node + n, [](int a,int b){ return deg[a] > deg[b];});
	int ptr = 0;
	memset(col, -1, sizeof col);
	for(int i = 0; i < n; i ++) {
		int a = node[i];
		for(auto e: g[a]) {
			if(col[e] == -1) {
				col[e] = ptr ++;
			}
		}
	}

	for(int i = 0; i < n - 1; i ++) cout << col[i] << endl;


	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
vector<int> g[N], r[N];
vector<int> path;

int n,m,u,v;
int dis[N], rdis[N];
int source, sink;
void bfs(int s, vector<int> g[], int dis[]) {
	queue<int> q;
	q.push(s);
	for(int i = 0; i <N; i++) dis[i] = 1e9;
	dis[s] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(auto v: g[u]) {
			if(dis[v] > 1 + dis[u]) {
				dis[v] = 1 + dis[u];
				q.push(v);
			}
		}
	}
}

int calcMin() {
	int ans = 0;
	int pivot = source;
	for(int i = 1; i < path.size(); i ++) {
		pivot = path[i-1];
		int choice = path[i];
		if(rdis[choice] + 1 == rdis[pivot]) continue;
		else ans ++;
	}
	return ans;
}

int calcMax() {
	int ans = 0;
	int pivot = source;
	for(int i = 1; i < path.size(); i ++) {
		pivot = path[i-1];
		int choice = path[i];
		int iMin = 1e9;
		for(auto v: g[pivot]) {
			iMin = min(iMin, rdis[v]);
		}
		int cnt = 0,pick = -1;
		for(auto v: g[pivot]) {
			if(rdis[v] == iMin) cnt ++, pick = v;
		}
		if(cnt > 1 || pick != choice) ans ++;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i ++) {
		cin >> u >> v;
		g[u].push_back(v);
		r[v].push_back(u);
	}
	int k;
	cin >> k;
	for(int i = 0; i < k; i ++) {
		int v;
		cin >> v;
		path.push_back(v);
	}
	source = path[0], sink = path.back();
	bfs(source, g, dis);
	bfs(sink, r, rdis);
	cout << calcMin() << " " <<calcMax() << endl;
	return 0;
}

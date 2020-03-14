#include <bits/stdc++.h>
using namespace std;
string g[505];
int main() {
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n ; i ++) {
		cin >> g[i];
	}
	int ans = 0;
	for(int u = 0; u < n; u ++) {
		vector<bool> isOk(m,true);
		for(int k = 0; k < m ; k ++) isOk[k] = (g[u][k] == '.');
		for(int d = u + 1; d < n; d++) {
			for(int k = 0; k < m; k ++) isOk[k] = isOk[k] & (g[d][k] == '.');
			int iMin = m + 1;
			int iMax = -1;
			for(int k = 0; k < m; k ++) {
				if(g[u][k] == '.' && g[d][k] == '.') {
					iMin = min(iMin, k);
					iMax = max(iMax,k);
				}
			}	
			if(iMax == -1 || iMin == iMax) continue;
			ans = max(ans, (d - u) + ( iMax - iMin));
		}
	}
	if(ans) cout << 2* ans << endl;
	else cout << "impossible" << endl;
}

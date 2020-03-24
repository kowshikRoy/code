#include <bits/stdc++.h>
using namespace std;

 q
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int p[n + 1] , c[n+1];
		for(int i = 1; i <= n; i++) cin >> p[i];
		for(int i = 1; i <= n; i++) cin >> c[i];

		int b[n + 1];
		for(int i = 1; i <= n; i ++) {
			b[i] = p[p[i]];
		}
		int d[n + 1];
		int e[n + 1];
		for(int i = 1; i <= n; i ++) {
			d[i] = b[p[i]];
			e[i] = p[b[i]];
		}

		for(int i  = 1; i <= n; i ++) cout << d[i] << " " << e[i] << endl;

	}



	return 0;
}

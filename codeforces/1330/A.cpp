#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		int x;
		cin >> n >> x;
		int a[n];
		int vis[500] = {0};
		for(int i = 0; i < n; i ++) cin >> a[i], vis[a[i]] = 1;
		int ans = 0;
		for(int i = 1; i <= 500 ; i ++) {
			if(vis[i] ) {
				ans = i;
				continue;
			}
			else if(x > 0) {
				ans = i;
				x --;
			}
			else break;
		}
		cout << ans << endl;

	}
	return 0;
}

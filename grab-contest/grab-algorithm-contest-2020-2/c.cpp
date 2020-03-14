#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int ans = -1;
		for(int i = 0; i <= n; i += 3) {
			int rm = n - i;
			if(rm % 5 == 0) {
				ans = i;
			}
		}
		if(ans == -1) {
			cout << -1 << endl;
			continue;
		}
		for(int i = 0; i < ans; i ++) cout << 5 ;
		for(int i = ans; i < n; i ++) cout << 3 ;
		cout << endl;
	}
	return 0;
}

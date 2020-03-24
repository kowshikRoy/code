#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	long long a[n + 1];
	for(int i = 1; i <= n; i ++) cin >> a[i];

	int q;
	cin >> q;
	for(int i = 0; i < q; i ++) {
		int x, y;
		cin >> x >> y;
		if(x == 1) cout << a[y] << "\n";
		else {
			long long sum = 0;
			for(int i = y - x; i <= y; i ++) sum += a[i];
			long long sum2 = (y - x) * a[y];
			cout << min(sum, sum2) + a[y] << "\n";
		}
	}
	return 0;
}

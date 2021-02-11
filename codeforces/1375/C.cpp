#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n + 1];
		for(int i = 1; i <= n; i ++) cin >> a[i];
		printf("%s\n", (a[1] < a[n]) ? "YES" : "NO");
	}

	return 0;
}

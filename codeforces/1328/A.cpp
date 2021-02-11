#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int a;
		int b;
		cin >> a >> b;
		if(a % b == 0) cout << 0 << endl;
		else cout << 1LL * (a/b + 1) * b - a << endl;
	}

	return 0;
}

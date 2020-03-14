#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string a, b, c;
		cin >> a >> b >> c;
		bool flag = 1;
		for (int i = 0; i < (int)a.size(); i++) {
			swap(a[i], c[i]);
			if (a[i] == b[i])
				continue;
			swap(a[i], c[i]);
			swap(b[i], c[i]);
			if (a[i] == b[i])
				continue;
			flag = 0;
			break;
		}
		printf("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}

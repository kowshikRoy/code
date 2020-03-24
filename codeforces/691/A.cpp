#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 1; i <= n; i ++) {
		int x;
		cin >> x;
		if(x == 0) cnt ++;
	}
	if(n == 1) {
		printf("%s\n", cnt == 0 ? "YES" : "NO");
	}
	else printf("%s\n", cnt == 1 ? "YES" : "NO");

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	bool odd = false, even = false;
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
		if(a[i] & 1) odd = 1;
		else even = 1;
	}
	if(odd && even) {
		sort(a,a+n);
	}
	for(int i = 0; i < n; i ++) cout << a[i] << " ";

	return 0;
}

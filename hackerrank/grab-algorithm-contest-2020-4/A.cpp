#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	long long a[n];
	long long ans = 1e18;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a,a+n);
	for(int i = 1; i < n; i ++) {
		ans = min(ans, a[i] - a[i-1]);
	}
	cout << ans << endl;
}

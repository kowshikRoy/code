#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	long long n;
	cin >> n;
	long long ans = 0;
	while(n) {
		if( (n%2 == 0) ) ans ++;	
		n /=2;
	}
	cout << (1LL << ans) << endl;
	return 0;
}

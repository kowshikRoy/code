#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		long long n,k;
		cin >> n >> k;
		long long sum = k * k;
		if(n >= sum && (n % 2 == sum % 2)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}


	return 0;
}

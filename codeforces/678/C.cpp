#include <bits/stdc++.h>
using namespace std;

long long lcm(long long a,long long b) {
	return a*b/__gcd(a,b);
}
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	long long n,a,b,p,q;
	cin >> n >> a >> b >> p >> q;
	long long ans = n / lcm(a,b) * max(p,q) + (n / a - n / lcm(a,b)) * p + (n / b - n/lcm(a,b)) * q;
	cout << ans << endl;

	return 0;
}

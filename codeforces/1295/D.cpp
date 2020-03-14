#include <bits/stdc++.h>
using namespace std;

template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}

vector<int> isPrime;
void seive(int n) {
	isPrime.resize(n+1,1);
	isPrime[0] = isPrime[1] = 0;
	for(int i = 2; i <= n; i ++) {
		if(isPrime[i]) {
			for(int j = i + i; j <= n; j +=i) isPrime[j] = 0;
		}
	}
}

long long phi(long long n) {
	long long ans = n;
	for(int i = 1; i <= n/i; i ++) {
		if(isPrime[i] && n%i == 0) {
			ans -= ans/i;
			while(n%i == 0)n/=i;
		}
	}
	if(n > 1) ans -= ans/n;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	seive(100004);
//	for(int i = 1; i <= 100; i ++) printf("isPrime[%d] = %d\n",i,isPrime[i]);
	int t;
	cin >> t;
	while(t--) {
		long long a,m;
		cin >> a >> m;
		auto g = gcd(a,m);
		cout << phi(m/g) << endl;
	}


	return 0;
}

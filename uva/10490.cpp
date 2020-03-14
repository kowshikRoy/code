#include <bits/stdc++.h>
using namespace std;

using ll = long long unsigned;
bool check(long long n) {
	for(long long i = 2; i * i <= n; i ++) {
		if(n % i == 0) return false;
	}
	return true;
}

map<ll,ll> factor(ll n) {
	map<ll,ll> ret;
	for(long long i = 2; i * i <= n; i ++) {
		while(n % i == 0) ret[i] ++, n/=i;
	}
	if(n > 0) ret[n] ++;
	return ret;
}

ll powc(ll a, ll b) { 
	ll ret =1;
	while(b -- ) ret *= a;
	return ret;
}
ll calc(ll a, ll b) {
	return (powc(a,b+1) - 1) / (a - 1);
}
int main() {
	ll n;
	while(cin >> n) {
		if(n == 0) break;
		ll v = (1ULL << (n-1)) * ((1ULL << n) - 1);
		map<ll,ll> f = factor((1ULL << n) - 1);
		f[2] += n - 1;
		
		ll sum = 1;
		for(auto x: f) {
			sum *= calc(x.first, x.second);
		}
		if(sum/2 == v) 
			printf("Perfect: %llu!\n", v);
		else {
			if(check(n)) printf("Given number is prime. But, NO perfect number is available.\n");
			else printf("Given number is NOT prime! NO perfect number is available.\n");
		}
	}
}

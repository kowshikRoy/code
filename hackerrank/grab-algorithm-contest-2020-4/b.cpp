#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++) {
		long long a,b,c, sum = 0, tot = 0;
		cin >> a>> b >> c;
		tot = 2 * a * b;
		if(a > b) swap(a,b);
		if(c < a) {
			sum = c * c;
		}
		else if(c >= a && c < b) {
			sum = 2 * (c - a) * a + a * a;
		}
		else if(c >= b && c < a + b) {
			sum = 2 * a * b - (a + b - c) * (a + b -c);
		}
		else sum = 2 * a * b;

		long long g = __gcd(sum,tot);
		cout << sum / g << "/" << tot / g << endl;

	}
}

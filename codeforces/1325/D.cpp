#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	LL u,v;
	cin >> u >> v;
	if(u == 0 && v == 0) {
		cout << 0 << endl;
		return 0;
	}

	if(u == v) {
		cout << 1 << endl;
		cout << u << endl;
		return 0;
	}

	if( u > v) {
		cout << -1 << endl;
		return 0;
	}

	LL x = (v - u)/2;
	LL A, B , i = 0;
	bool flag = true;
	while(x || u) {
		int b1 = x & 1, b2 = u & 1;
		if(b1 == 1 && b2 == 1) {
			flag = false;
			break;
		}
		if(b1 == 1 && b2 == 0) {
			A = (1LL << i) + A;
			B = (1LL << i) + B;
		}
		if(b1 == 0 && b2 == 1) {
			A = (1LL << i) + A;
		}
		x/=2;
		u/=2;
		i ++;
		
	}
	if(flag == false) {
		if( v % u == 0 && ( (v/u) & 1)) {
			cout << v / u << endl;
			for(int i = 0; i < v/u ; i ++) {
				cout << u << " ";
			}
		}
	}
	else {
		cout << 2 << "\n" << A << " " << B << endl;
	}


	return 0;
}

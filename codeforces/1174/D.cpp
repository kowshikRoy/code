#include <bits/stdc++.h>
using namespace std;

const int N = 1<<18;
int n,x;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> x;
	vector<int>b;
	int a[1<<n];
	if(x >= (1<<n)) {
		for(int i = 1; i < 1 << n; i ++) b.push_back(i);
	}
	else {
		for(int i = 1; i < (1 << n); i ++) {
			int p = x ^ i;
			if(p == 0) continue;
			if(i < p) b.push_back(i);
		}
	}
	cout << b.size() << endl;
	int pre = 0;
	for(auto x : b) {
		cout << (x ^ pre) << " ";
		pre = x;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	int cnt = 0;
	int iMax = 0;
	int pre = INT_MAX;
	for(int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		if(x > pre) cnt ++;
		else {
			iMax = max(cnt, iMax);
			cnt = 1;
		}
		pre = x;
	}
	iMax = max(cnt, iMax);
	cout << iMax << endl;

	return 0;
}

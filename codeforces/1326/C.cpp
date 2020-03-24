#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,k;
	cin >> n >> k;
	int A[n + 1];
	int pos[n + 1];
	int M = 998244353;
	for(int i = 1; i <= n; i ++) {
		cin >> A[i];
		pos[A[i]] = i;
	}

	int LIM = n - k + 1;
	int pre = -1;
	long long ans = 1;
	long long sum = 0;
	for(int i = 1; i <= n; i ++) {
		if(A[i] >= LIM) {
			sum += A[i];
			if(pre >= 0) ans = (ans *  (i - pre )) % M;
			pre = i;
		}
	}
	cout << sum << " " << ans << endl;

	return 0;
}

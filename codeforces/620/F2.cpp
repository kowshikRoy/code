#include <bits/stdc++.h>
using namespace std;
int a[50004];
int L[5005], R[5005];

int dp[50005];
int ans[5005];
int p[1000005];

int main() {
	for (int i = 1; i <= 1000000; i++)
		p[i] = p[i - 1] ^ i;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++) {
		cin >> L[i] >> R[i];
	}
	for (int i = 1; i <= n; i++) {
		int best = 0;
		for (int j = i; j <= n; j++) {
			best = max(best, p[a[i]] ^ p[a[j]] ^ min(a[i], a[j]));
			dp[j] = best;
		}
		for (int j = 1; j <= m; j++) {
			if (i >= L[j]) {
				ans[j] = max(ans[j], dp[R[j]]);
			}
		}
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << endl;
}

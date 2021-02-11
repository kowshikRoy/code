#include <bits/stdc++.h>
using namespace std;

const int M = 1e4 + 4;
int u[M], v[M], c[M];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i] >> c[i];
	}

	int A, B;
	cin >> A >> B;
	int dp[1005], dp2[1005];

	for (int i = 0; i <= n; i++)
		dp[i] = (1 << 30) - 1;
	int iM = dp[0];
	dp[A] = 0;
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 1; j <= n; j++)
			dp2[j] = dp[j];
		for (int j = 0; j < m; j++) {
			dp2[v[j]] = min(dp2[v[j]], dp[u[j]] | c[j]);
			dp2[u[j]] = min(dp2[u[j]], dp[v[j]] | c[j]);
		}
		for (int j = 1; j <= n; j++)
			dp[j] = min(dp[j], dp2[j]);
	}

	printf("%d\n", dp[B] == iM ? -1 : dp[B]);
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int x[n];
		for (int j = 0; j < n; j++) {
			cin >> x[j];
		}
		for (int j = 0; j < n; j++) {
			if (j % 2)
				x[j] = abs(x[j]);
			else
				x[j] = -abs(x[j]);
		}
		for (int j = 0; j < n; j++)
			printf("%d ", x[j]);
		printf("\n");
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int dir[][2] = {{1, 0}, {0, 1},{0, -1}, {-1, 0}};
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int c[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cin >> c[i][j];
		}

		bool flag = true;
		for (int i = 0; i < n && flag; i++) {
			for (int j = 0; j < m && flag; j++) {
				int cnt = 0, neigh = 0;
				for (int d = 0; d < 4; d++) {
					int x = i + dir[d][0], y = j + dir[d][1];
					if (x < 0 || x >= n || y < 0 || y >= m)
						continue;
					neigh++;
				}
				if (c[i][j] > neigh) {
					flag = 0;
					break;
				}
				c[i][j] = neigh;
			}
		}
		if(flag) {
			printf("YES\n");
			for(int i = 0; i < n; i ++) {
				for(int j = 0; j < m; j ++) printf("%d ", c[i][j]);
				printf("\n");
			}
		}
		else printf("NO\n");
	}

	return 0;
}

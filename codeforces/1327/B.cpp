#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int>taken(n + 1, 0);
		vector<int > un;
		vector<int> choice[n+1];
		
		for (int i = 1; i <= n; i++) {
			int k;
			cin >> k;
			for (int j = 0; j < k; j++) {
				int p;
				cin >> p;
				choice[i].push_back(p);
			}
			bool flag = 0;
			for (auto p : choice[i]) {
				if (taken[p] == 0) {
					taken[p] = 1;
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				un.push_back(i);
		}
		if (un.size() == 0) {
			cout << "OPTIMAL\n";
		} else {
			int pivot = un[0];
			for (int i = 1; i <= n; i++) {
				if (taken[i] == 0) {
					cout << "IMPROVE\n";
					cout << pivot << " " << i << endl;
					break;
				}
			}
		}
	}

	return 0;
}

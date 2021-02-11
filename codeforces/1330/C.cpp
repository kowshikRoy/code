#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	long long sum = 0;
	long long l[m + 1], sl[m + 1];
	for (int i = 0; i < m; i++) {
		cin >> l[i];
		sum += l[i];
	}
	sl[m] = 0;
	for (int i = m - 1; i >= 0; i--) {
		sl[i] = l[i] + sl[i + 1];
	}
	vector<int> ans;
	int pb = 0, pe = 0;
	bool flag = 1;
	for (int i = 0; i < m; i++) {
		int x = l[i];
		int minX = n - sl[i] + 1;
		int nb = max(minX, pb + 1);
		int ne = nb + l[i] - 1;
		if(nb > pe + 1 || nb <= pb) {
			flag = 0;
			break;
		}
		if(ne > n) {
			flag = 0;
			break;
		}
		ans.push_back(nb);
		pb = nb;
		pe = ne;
	}

	if (flag && pe == n) {
		for (int i : ans)
			cout << i << " ";
	} else
		cout << -1 << endl;

	return 0;
}


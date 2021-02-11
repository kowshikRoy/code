#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &a, int x, int y, int len) {
	set<int> s;
	for (int i = x; i <= y; i++)
		s.insert(a[i]);
	for (int i = 1; i <= len; i++) {
		if (s.count(i) == 0)
			return 0;
	}
	return 1;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			a.push_back(x);
		}
		int l1 = *max_element(a.begin(), a.end());
		int l2 = n - l1;
		if (l1 >= 1 && l2 >= 1) {
			vector<pair<int, int>> ans;
			if (check(a, 0, l2 - 1, l2) && check(a, l2, n - 1, l1))
				ans.push_back({l2, l1});
			if (l1 != l2 && check(a, 0, l1 - 1, l1) && check(a, l1, n - 1, l2))
				ans.push_back({l1, l2});
			cout << ans.size() << endl;
			for (auto i : ans)
				cout << i.first << " " << i.second << endl;
		} else {
			cout << 0 << endl;
		}
	}

	return 0;
}

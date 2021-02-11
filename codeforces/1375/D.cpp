#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		vector<int> ans;
		for(int i = 0; i < n ;i ++) cin >> a[i];
		for(int loop = 0; loop < 2*n; loop ++) {
			bool flag = true;
			for(int i = 0; i < n - 1; i ++) {
				if(a[i] > a[i + 1]) {
					flag = false;
				}

			}
			if(flag) break;
			set<int> s;
			int mex = -1;
			for(int i = 0; i < n; i ++) s.insert(a[i]);
			for(int i = 0; i <= n; i ++) {
				if(s.count(i) == 0) {
					mex = i;
					break;
				}
			}
			ans.push_back(mex);
			if(mex == 0) a[0] = 0;
			else a[mex - 1] = mex;
		}
		cout << ans.size() << endl;
		for(int i = 0; i < n; i ++) cout << a[i] << " "; cout << endl;
		for(auto p: ans) cout << (p + 1) << " ";
		cout << endl;
	}

		
	return 0;
}

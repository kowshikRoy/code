#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		vector<string> buc(k);
		for(int i = 0; i < n; i ++) {
			buc[i % k].push_back(s[i]);
		}
		cout << buc[(n-1) % k] << endl;
	}
		
	return 0;
}

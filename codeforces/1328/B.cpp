#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		long long n, k;
		cin >> n >> k;
		int a = n - 2, b = 2;
		k--;
		string ans;
		for (int i = 1; i <= n; i++) {
			bool flag = 0;
			if(b) {
				int way  = 0;
				if(b > 0) way = a;
				else way = 0;
				if(k >= way) {
					ans.push_back('b');
					k -= way;
					b --;
					flag = 1;
				}
			}
			if(flag == 0){
				ans.push_back('a');
				a --;
			}
		}

		cout << ans << endl;
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int sign(long long a) { return a > 0 ? 1 : -1; }
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		long long n, x;
		string s;
		cin >> n >> x;
		cin >> s;
		s += s;
		long long sum = 0;
		map<long long,int> cnt;
		cnt[0] = 1;
		for (int i = 0; i < s.length(); i++) {
			sum += (s[i] == '1') ? -1 : 1;
			cnt[sum] ++;
		}
		// cout << sum << endl;
		if (sum == 0) {
			printf("%d\n", cnt.count(x) ? -1 : 0);
			continue;
		}
		long long psum = (x / sum) * sum - sum;
		if(sign(psum) * sign(sum) < 0) psum = 0;
		s = s + s + s;
		long long ans = 0;
		for(int i = 0; i < s.size(); i ++) {
			psum += (s[i] == '1') ? -1 : 1;
			if (psum == x) ans ++;
		}
		cout << ans << endl;
	}
	return 0;
}

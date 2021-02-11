#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	map<long long, long long> m;

	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i], m[a[i]]++;

	map<long long, long long> pfsum, pfcnt, sfsum, sfcnt;
	long long sum = 0, cnt = 0;
	for (auto x : m) {
		sum += x.second * x.first;
		cnt += x.second;
		pfsum[x.first] = sum;
		pfcnt[x.first] = cnt;
	}

	sum = 0, cnt = 0;
	for (auto x = m.rbegin(); x != m.rend(); x++) {
		sum += x->second * x->first;
		cnt += x->second;
		sfsum[x->first] = sum;
		sfcnt[x->first] = cnt;
	}

	sort(a, a + n);
	long long ans = 1e18;
	for (int i = 0; i < n; i++) {
		int x = a[i];
		if (m[x] >= k) {
			ans = 0;
			break;
		}
		if (i > 0) {
			long long pfs = pfsum[a[i - 1]], cnt = pfcnt[a[i - 1]];
			long long tmp = cnt * a[i - 1] - pfs;
			if(cnt >= k - m[x]) {
				tmp += (k - m[x]) * (a[i] - a[i - 1]);
				ans = min(ans, tmp);
			}
		}
		if (i + 1 < n) {
			long long pfs = sfsum[a[i + i]], cnt = sfcnt[a[i + 1]];
			long long tmp = pfs - cnt * a[i + 1];
			if (cnt >= k - m[x]) {
				tmp += (k - m[x]) * (a[i + 1] - a[i]);
				tmp += min(ans, tmp);
			}
		}
		cout << ans << endl;
		return 0;
	}
}

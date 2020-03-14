#include <bits/stdc++.h>
using namespace std;

int a[100005];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,k;
	cin >> n >> k;
	for(int i = 0; i < n;i ++) {
		cin >> a[i];
	}
	sort(a,a+n);
	multiset<int> s;
	for(int i = 0; i < k -1; i ++) s.insert(a[i]);
	int ans = INT_MAX;
	for(int i = k-1; i < n; i ++) {
		s.insert(a[i]);
		int low = *s.begin();
		int high = *s.rbegin();
		ans = min(ans, high - low);
		s.erase(s.find(a[i-k+1]));
	}
	cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 4e5+5;

struct seg {
	int first, second, id;
	bool operator < (const seg &rhs) const {
		return second < rhs.second;
	}
}p[N];

int B[N];
int query(int x) {
	int sum = 0;
	while(x) sum += B[x], x -= x&-x;
	return sum;
}

void update(int x, int v) {
	while(x < N) B[x] += v, x += x&-x;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	vector<int> vec;
	for(int i = 0; i < n; i ++) {
		cin >> p[i].first >> p[i].second;
		p[i].id = i;
		vec.push_back(p[i].first);
		vec.push_back(p[i].second);
	}
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());

	for(int i = 0; i < n ;i ++) {
		p[i].first = lower_bound(vec.begin(), vec.end(), p[i].first) - vec.begin() + 1;
		p[i].second = lower_bound(vec.begin(), vec.end(), p[i].second) - vec.begin() + 1;
	}

	sort(p, p + n);
	int ans[n + 1];
	for(int i = 0; i < n; i ++) {
		int L = p[i].first, R = p[i].second;
		ans[p[i].id] = query(R) - query(L);
		update(L,1);
	}

	for(int i = 0; i < n; i ++) cout << ans[i] << endl;



	return 0;
}

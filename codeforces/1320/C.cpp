#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;

pair<int, int> A[N], B[N];
struct mon {
	int x, y, z;
	bool operator<(const mon &rhs) const {
		if (x == rhs.x)
			return y < rhs.y;
		return x < rhs.x;
	}
} mons[N];
int n, m, p;
////int bits[N];
////
////void update(int x, int v) {
////	while (x < N)
////		bits[x] += v, x += x & -x;
////}
////
////int query(int x) {
////	int sum = 0;
////	while (x)
////		sum += bits[x], x -= x & -x;
////	return sum;
////}
////
long long seg[5 * N];
long long lazy[5 * N];
void update(int n, int b, int e, int i, int j, long long v) {
	if (b > j || e < i)
		return;
	if (lazy[n]) {
		seg[n] += lazy[n];
		if (b != e)
			lazy[2 * n] += lazy[n], lazy[2 * n + 1] += lazy[n];
		lazy[n] = 0;
	}
	if (b >= i && e <= j) {
		seg[n] += v;
		if (b != e)
			lazy[2 * n] += v, lazy[2 * n + 1] += v;
		return;
	}
	int mid = (b + e) / 2;
	update(2 * n, b, mid, i, j, v);
	update(2 * n + 1, mid + 1, e, i, j, v);
	seg[n] = max(seg[2 * n], seg[2 * n + 1]);
}

long long query(int n, int b, int e, int i, int j) {
	if (b > j || e < i)
		return LONG_LONG_MIN;
	if (lazy[n]) {
		seg[n] += lazy[n];
		if (b != e)
			lazy[2 * n] += lazy[n], lazy[2 * n + 1] += lazy[n];
		lazy[n] = 0;
	}
	if (b >= i && e <= j) {
		return seg[n];
	}
	int mid = (b + e) / 2;
	return max(query(2 * n, b, mid, i, j), query(2 * n + 1, mid + 1, e, i, j));
}
int abits[N], bbits[N];
void update(int B[], int x, int v) {
	while (x > 0)
		B[x] = min(B[x], v), x -= x & -x;
}

int query(int B[], int x) {
	int sum = INT_MAX;
	while (x < N)
		sum = min(sum, B[x]), x += x & -x;
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> p;
	for (int i = 0; i < N; i++)
		abits[i] = bbits[i] = INT_MAX;
	for (int i = 0; i < n; i++) {
		cin >> A[i].first >> A[i].second;
		update(abits, A[i].first, A[i].second);
	}

	for (int i = 0; i < m; i++) {
		cin >> B[i].first >> B[i].second;
		update(bbits, B[i].first, B[i].second);
	}

	for (int i = 0; i < p; i++) {
		cin >> mons[i].x >> mons[i].y >> mons[i].z;
	}
	sort(mons, mons + p);

	for (int i = 1; i <= 1000000; i++) {
		long long bw = query(bbits, i + 1);
		update(1, 1, 1000000, i, i, -bw);
	}

	long long profit = 0;
	for (int i = 0; i < p; i++) {
		update(1,1,1000000, mons[i].y , 1000000, mons[i].z);
		long long res = query(1,1,1000000,1,1000000);
		long long aw = query(abits, mons[i].x + 1 );
		profit = max(profit, res - aw);
	}
	cout << profit << endl;
	return 0;
}

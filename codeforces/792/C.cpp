#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
string s;
int dp[N][3][2];
bool check() {
	for (char c : s)
		if (c == '0')
			return 1;
	return 0;
}

int solve(int idx, int rem, bool flag) {
	if (idx == s.size()) {
		return rem == 0 ? 0 : -1000000;
	}
	if (dp[idx][rem][flag] != -1)
		return dp[idx][rem][flag];
	int a = INT_MIN, b = solve(idx + 1, rem, flag);
	a = 1 + solve(idx + 1, (rem + s[idx] - '0') % 3, flag | (s[idx] - '0'));
	if(flag == 0 && s[idx] == '0') a = INT_MIN;
	return dp[idx][rem][flag] = max(a, b);
}

string ans;
void dfs(int idx, int rem, bool flag) {
	if (idx == s.size())
		return;
	int a = 1 + solve(idx + 1, (rem + s[idx] - '0') % 3, flag | (s[idx] - '0'));
	int b = solve(idx + 1, rem, flag);
	if(flag == 0 && s[idx] == '0') a = INT_MIN;
	if (a >= b) {
		ans.push_back(s[idx]);
		dfs(idx + 1, (rem + s[idx] - '0') % 3, flag | (s[idx] - '0'));
	} else
		dfs(idx + 1, rem, flag);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	memset(dp,-1,sizeof dp);
	int length = solve(0,0,0);
	if(length <= 0) {
		if(check()) cout << "0" << endl;
		else cout << -1 << endl;
		return 0;
	}
	dfs(0,0,0);
	cout << ans << endl;
	return 0;
}

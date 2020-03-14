#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int im1 = 0, im2 = 0;
	char pre = 'W';
	int cur = 0;
	for(int i = 0; i < n; i ++) {
		string s;
		cin >> s;
		if(pre != s[0]) {
			cur = 1;
		}
		else cur ++;
		pre = s[0];

		if(pre == 'H') im1 = max(im1, cur);
		if(pre == 'T') im2 = max(im2, cur);
	}
	cout << im1 << " " << im2 << endl;
}

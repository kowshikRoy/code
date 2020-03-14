#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int a;
	cin >> s;
	cin >> a;
	int value[140];
	value['a'] = a;
	for(int i = 'b'; i <= 'z'; i ++) {
		value[i] = value[i-1] + 1;
		if(value[i] > 25) value[i] = 0;
	}
	int sum = 0;
	for(char c: s) {
		sum += value[c];
	}
	cout << sum << endl;
}

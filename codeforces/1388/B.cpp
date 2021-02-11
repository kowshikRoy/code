#include <bits/stdc++.h>
using namespace std;

int toBin(string s){
	int ans = 0;
	for(int i = 0; i < s.size(); i ++) ans = 2*ans + s[i] - '0';
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> t;
	while(t--) {

		int n;
		cin >> n;
		string s;
		for(int i = 0; i < n; i ++) s += "1001";
		for(int i = s.size() - 1, c = 0; c < n; c ++, i --) {
			s[i] = '0';
			if((c+1) % 4 == 0) s[i] = '1';
		}
		
		for(int i = 0; i < s.size(); i +=4) {
			cout << toBin(s.substr(i, 4));
		}
		cout << endl;
	}


	return 0;
}

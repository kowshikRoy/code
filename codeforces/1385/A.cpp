#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int c[3];
		cin >> c[0] >> c[1] >> c[2];
		sort(c,c+3);
		if(c[1] == c[2]) {
			cout << "YES" << endl;
			if(c[0] == c[1]) cout << c[0] << " " << c[1] << " " << c[2] << endl;
			else cout << c[0] << " " << c[0] << " " <<c[2] << endl;
		}
		else cout << "NO" << endl;
	}


	return 0;
}

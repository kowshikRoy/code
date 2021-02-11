#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	long long a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	int ans = 0;
	for(int i = 0; i < n; i ++) {
		if(a[i] % 2 == 0) continue;
		
		if(i + 1 < n) {
			a[i + 1] ++;
			a[i] ++;
			ans += 2;
		}
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << ans << endl;

}

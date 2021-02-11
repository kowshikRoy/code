#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,l;
	cin >> n >> l;
	string vs[n];
	for(int i = 0; i < n; i ++) {
		cin >> vs[i];
	}
	sort(vs,vs+n,[](string a,string b){return a + b < b + a;});
	string ans;
	for(auto s: vs) ans += s;
	cout << ans << endl;

}

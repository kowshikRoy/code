#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n%2==0) {
			for(int i = 0;i <n/2;i++)cout <<"1";
		}
		else {
			cout<<"7";
			n-=3;
			for(int i = 0;i <n/2;i++)cout <<"1";
		}
		cout << endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	char win;
	cin >> win;
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++) {
		char c1,c2;
		int n1,n2;
		cin >> c1 >> n1 >> c2 >> n2;
		if(c1 == win && c2 == win) {
			if(n1 == n2) cout << "Draw" << endl;
			else printf("Player %d wins\n", n1 > n2 ? 1 : 2);
		}
		else if(c1 == win) printf("Player 1 wins\n");
		else if(c2 == win) printf("Player 2 wins\n");
		else {
			if(n1 == n2) cout << "Draw" << endl;
			else printf("Player %d wins\n", n1 > n2 ? 1 : 2);
		}
	}


}

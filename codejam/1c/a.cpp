#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,cs = 0;
	cin >> t;
	while(t--) {
		int x,y;
		string s;
		int ans = -1, Time = 0;
		cin >> x >> y >> s;
		for(char c: s) {
			if(c == 'E') x ++;
			if(c == 'W') x --;
			if(c == 'S') y --;
			if(c == 'N') y ++;
			Time ++;
			if(abs(x) + abs(y) <= Time) {
				ans = Time;
				break;
			}
		}
		if(ans == -1) printf("Case #%d: IMPOSSIBLE\n", ++cs);
		else printf("Case #%d: %d\n", ++cs,ans);
	}
}

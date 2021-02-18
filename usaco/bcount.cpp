#include <bits/stdc++.h>
using namespace std;

void setIO(string s) { // the argument is the filename without the extension
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
int p[100005][4];
int main(){
    setIO("bcount");
    int n,q;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) {
        int a;
        cin >> a; a--;
        for(int j = 0; j < 3; j ++) p[i][j] = p[i-1][j];
        p[i][a] ++;
    }
    while(q--) {
        int l,r;
        cin >> l >> r;
        for(int j = 0; j < 3; j ++) {
            if(j) cout << " ";
            cout << p[r][j] - p[l-1][j];
        }
        cout << endl;
    }

}

/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-04
 * Task: A 
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)


int main() {

    int t,cs = 0;;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        printf("Case %d: ",++cs);
        if(s[4] == 's') {
            cout << s << endl;
        }
        else {
            s.insert(4,1, 's');
            cout<<s<<endl;
        }
    }
    return 0;
}


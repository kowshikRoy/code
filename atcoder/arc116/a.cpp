/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-28
 * Task: a 
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve() {
   ll n;
   cin>>n;
   int cnt = 0;
   while(n % 2 == 0) cnt ++, n/=2;
   if(cnt == 1) cout << "Same\n";
   else if(cnt > 1) cout << "Even\n";
   else cout << "Odd\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}


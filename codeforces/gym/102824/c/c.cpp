/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-02
 * Task: c
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n), B(n), apos(n), bpos(n);
    REP(i, n) cin >> A[i], A[i]--, apos[A[i]] = i;
    REP(i, n) cin >> B[i], B[i]--, bpos[B[i]] = i;

    ll ans = 0;
    set<pair<int, int>> g, l, e;
    ll R = 0, L = 0;
    REP(i, n) {
        ans += abs(apos[i] - bpos[i]);
        if (bpos[i] > apos[i]) {
            g.insert({bpos[i] - apos[i], i});
            R += bpos[i] - apos[i];
        } else if (bpos[i] < apos[i]){
            l.insert({apos[i] - bpos[i], i});
            L += apos[i] - bpos[i];
        }
        else e.insert({0, i});
    }

    ll fans = ans;
    REP(i,n) {
        // move ith element to the last
        ans = -g.size() + e.size() + l.size();
        while(e.size()) {

    
    }







    return 0;
}

/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-11
 * Task: FROGS 
 */

#include<bits/stdc++.h>
using namespace std;

struct Frog{
    int pos, weight, len;
    bool operator<(const Frog &rhs) const {
        return weight < rhs.weight;
    }
}frogs[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i ++) cin >> frogs[i].weight;
        for(int i = 0; i < n; i ++) cin >> frogs[i].len;
        for(int i = 0; i < n; i ++) frogs[i].pos = i;

        sort(frogs, frogs + n);
        int pre = -1, ans = 0;
        for(int i = 0; i < n; i ++) {
            if(frogs[i].pos <= pre) {
                int d = (pre + 1 - frogs[i].pos);
                int jump = d / frogs[i].len + ((d % frogs[i].len) ? 1 : 0);
                ans += jump;
                pre = frogs[i].pos + jump * frogs[i].len;
            }
            else pre = frogs[i].pos;
        }
        cout << ans << endl;
    }
                


}

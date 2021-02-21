/**
 * Author: Repon Kumar Roy
 * Date: 2021-02-21
 * Task: c 
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    string t = s;
    bool flag = true;
    /* long long ans = 0; */
    /* while(flag) { */
    /*     flag = false; */
    /*     for(int i = s.size() -2; i > 0; i --) { */
    /*         if(s[i-1] == s[i] && s[i+1] != s[i]) { */
    /*             s[i+1] = s[i]; */
    /*             ans ++; */
    /*             flag = true; */
    /*             cout << s << " " << i << endl; */
    /*             break; */
    /*         } */
    /*     } */
    /* } */
    /* cout << ans << endl; */
    int cnt[256];
    memset(cnt, 0, sizeof cnt);

    long long pans = 0;
    cnt[t[t.size()-1]] = 1;

    for(int i = t.size() - 2; i > 0 ; i --) {
        if(t[i-1] == t[i] && t[i + 1] != t[i]) {
            int v = (t.size() - i - 1 - cnt[t[i]]);
            /* cout <<  "added: " <<  v << endl; */
            pans += v;
            memset(cnt, 0, sizeof cnt);
            cnt[t[i]] = t.size() - i ;
        }
        else cnt[t[i]] ++;
        /* printf("%d = cnt[b] = %d\n",i, cnt['b']); */
    }
    cout << pans << endl;
}


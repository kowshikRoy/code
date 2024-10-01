#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << "]" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H; if(sizeof...(T)) cerr << ", "; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

/**
 * Author: Repon Kumar Roy
 * Date: 2021-05-01
 * Task: closest-pick 
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)


int main() {
    int t,cs = 0;
    cin>>t;
    while(t--) {
        int n,k;
        cin>> n>> k;

        vector<int> c(n);
        REP(i,n) cin >> c[i];
        vector<int> pos;
        pos.push_back(1);
        pos.push_back(k);
        REP(i,n) {
            if(c[i] > 1)  pos.push_back(c[i] - 1);
            if(c[i] + 1 <= k) pos.push_back(c[i] +1);
        }
        sort(pos.begin(), pos.end());
        pos.resize(unique(pos.begin(), pos.end()) - pos.begin());

        auto check = [&](int w, int a, int b) -> bool {
            int mind = INT_MAX;
            for(int i = 0; i < n; i ++) {
                mind = min(mind, abs(w - c[i]));
            }

            if(abs(w-a) < mind || abs(w-b) < mind) return true;
            /* if(abs(w-a) == abs(w-b) && abs(w-a) < mind) return true; */
            return false;
        };


        sort(c.begin(), c.end());

        int fans = 0;
        pair<int,int> opt;
        vector<int> optv;
        for(int i = 0; i < pos.size(); i ++) {
            for(int j = i + 1; j < pos.size(); j ++) {
                int A = pos[i];
                int B = pos[j];
                int ans = 0;
                bool flag = true;
                for(auto x: c) {
                    if(x == A) flag = false;
                    if(x == B) flag = false;
                }
                if(!flag) continue;
                vector<int> v;
                v.push_back(A);
                v.push_back(B);
                for(auto x: c) v.push_back(x);
                sort(v.begin(), v.end());

                for(int i = 0; i + 1< v.size(); i ++) {
                    int b = v[i] + 1, e = v[i+1] -1;
                    int mid = (b+e)/2;

                }
                // separate k;


                /* vector<int> vec; */
                /* for(int w = 1; w <= k; w ++) { */
                /*     if(check(w, A,B)) { */
                /*         ans ++; */
                /*         vec.push_back(w); */
                /*     } */
                /* } */
                /* if(ans > fans) { */
                /*     opt = {A,B}; */
                /*     optv = vec; */
                /*     fans = ans; */
                /* } */
            }
        }
        dbg(opt);
        dbg(optv);
        printf("Case #%d: %.9lf\n", ++cs, fans * 1./k);
    }
    return 0;
}


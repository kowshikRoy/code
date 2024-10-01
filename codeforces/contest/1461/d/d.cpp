#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
    os << '{';
    string sep;
    for (const T &x : v) os << sep << x, sep = ", ";
    return os << '}';
}

void dbg_out() { cerr << "]" << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
    cerr << H;
    if (sizeof...(T)) cerr << ", ";
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...)                                                       \
    cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", \
        dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-28
 * Task: d
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), pf(n);
    for (int i = 0; i < n; i++) { cin >> a[i]; }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) pf[i] = (i > 0 ? pf[i - 1] : 0) + a[i];

    set<int> s;
    function<void(int l, int r)> mergeSort = [&](int l, int r) {
        if (l == r) {
            s.insert(a[l]);
            return;
        }
        ll sum  = pf[r] - (l > 0 ? pf[l - 1] : 0);
        ll maxe = a[r], mine = a[l];
        s.insert(sum);
        if (mine == maxe) return;
        ll mid    = (maxe + mine) / 2;
        int pivot = -1;
        for (int i = l; i <= r; i++) {
            if (a[i] <= mid) { pivot = i; }
        }
        mergeSort(l, pivot);
        mergeSort(pivot + 1, r);
    };
    mergeSort(0, n - 1);
    cout <<s.size()<<endl;
    for (int i = 0; i < q; ++i) {
        ll x;
        cin >> x;
        if (s.count(x)) cout << "Yes\n";
        else
            cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}

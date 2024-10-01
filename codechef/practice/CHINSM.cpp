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
 * Date: 2021-04-03
 * Task: CHINSM
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

const int N = 1e1 + 5;
vector<int> d[N];

int main() {
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) d[j].push_back(i);
    }
    dbg("done");
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> a(n);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    vector<int> cnt(N, 0);

    auto add = [&](int x) {
        if(x <= 0) return;
        for (auto div : d[x]) cnt[div]++;
    };

    auto remove = [&](int x) {
        if(x <= 0) return;
        for (auto div : d[x]) cnt[div]--;
    };
    ll ans = 0;
    for (int l = 0, r = 0; r < n; r++) {
        int now = a[r];
        dbg(cnt);
        while (cnt[now] > 0) {
            remove(a[l] - k);
            l++;
        }
        ans += r - l + 1;
        dbg(l,r);
        add(a[r] - k);
    }
    printf("%lld\n", ans);

    return 0;
}

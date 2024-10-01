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
 * Date: 2021-04-02
 * Task: b
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    scanf("%d %d", &n, &p);

    deque<int> q[p + 1];
    for (int i = 1; i <= p; i++) {
        int k, a;
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &a);
            q[i].push_back(a);
        }
    }

    // make pile p to have all the stones
    vector<pair<int, int>> ins;
    for (int i = 1; i < p; i++) {
        while (q[i].size()) {
            q[p].push_front(q[i].front());
            q[i].pop_front();
            ins.push_back({i, p});
        }
    }

    // move all 1s into pile 1 from pile p
    // use 2 as intermediate
    while (q[p].size()) {
        int u = q[p].front();
        if (u == 1) {
            q[1].push_front(1);
            ins.push_back({p, 1});
        } else {
            q[2].push_front(u);
            ins.push_back({p, 2});
        }
        q[p].pop_front();
    }

    for (int i = 1; i <= p; i++) dbg(q[i]);
    // move all to pile 1
    while (q[2].size()) {
        int u = q[2].front();
        q[2].pop_front();
        q[1].push_front(u);
        ins.push_back({2, 1});
    }

    // put everything to their respective places
    while (q[1].size() && q[1].front() != 1) {
        int u = q[1].front();
        q[u].push_front(u);
        q[1].pop_front();
        ins.push_back({1, u});
    }
    for (int i = 1; i <= p; i++) dbg(q[i]);

    printf("%d\n", (int)ins.size());
    for (auto x : ins) { printf("%d %d\n", x.first, x.second); }

    return 0;
}

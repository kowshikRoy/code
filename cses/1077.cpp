/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-12
 * Task: 1077
 */

#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using ld  = long double;
using db  = double;
using str = string;  // yay python!

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

using vi  = vector<int>;
using vb  = vector<bool>;
using vl  = vector<ll>;
using vd  = vector<db>;
using vs  = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

#define tcT  template <class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
tcT > using PR = pair<T, T>;

// pairs
#define mp make_pair
#define f  first
#define s  second

#define sz(x) (int)(x).size()

// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a)    FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a)    ROF(i, 0, a)
#define trav(a, x)   for (auto& a : x)

// INPUT
#define tcTUU tcT, class... U
tcT > void re(complex<T>& c);
tcTU > void re(pair<T, U>& p);
tcT > void re(vector<T>& v);
tcT, size_t SZ > void re(AR<T, SZ>& a);

tcT > void re(T& x) { cin >> x; }
void re(db& d) {
    str t;
    re(t);
    d = stod(t);
}
void re(ld& d) {
    str t;
    re(t);
    d = stold(t);
}
tcTUU > void re(T& t, U&... u) {
    re(t);
    re(u...);
}

tcT > void re(complex<T>& c) {
    T a, b;
    re(a, b);
    c = {a, b};
}
tcTU > void re(pair<T, U>& p) { re(p.f, p.s); }
tcT > void re(vector<T>& x) { trav(a, x) re(a); }
tcT, size_t SZ > void re(AR<T, SZ>& x) { trav(a, x) re(a); }
tcT > void rv(int& n, vector<T>& x) {
    re(n);
    x.rsz(n);
    trav(a, x) re(a);
}

// TO_STRING
#define ts to_string
str ts(char c) { return str(1, c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) {
#ifdef LOCAL
    return b ? "true" : "false";
#else
    return ts((int)b);
#endif
}
tcT > str ts(complex<T> c) {
    stringstream ss;
    ss << c;
    return ss.str();
}
str ts(vector<bool> v) {
    str res = "{";
    F0R(i, sz(v)) res += char('0' + v[i]);
    res += "}";
    return res;
}
template <size_t SZ> str ts(bitset<SZ> b) {
    str res = "";
    F0R(i, SZ) res += char('0' + b[i]);
    return res;
}
tcTU > str ts(pair<T, U> p);
tcT > str ts(T v) {  // containers with begin(), end()
#ifdef LOCAL
    bool fst = 1;
    str res  = "{";
    for (const auto& x : v) {
        if (!fst) res += ", ";
        fst = 0;
        res += ts(x);
    }
    res += "}";
    return res;
#else
    bool fst = 1;
    str res  = "";
    for (const auto& x : v) {
        if (!fst) res += " ";
        fst = 0;
        res += ts(x);
    }
    return res;

#endif
}
tcTU > str ts(pair<T, U> p) {
#ifdef LOCAL
    return "(" + ts(p.f) + ", " + ts(p.s) + ")";
#else
    return ts(p.f) + " " + ts(p.s);
#endif
}

// OUTPUT
tcT > void pr(T x) { cout << ts(x); }
tcTUU > void pr(const T& t, const U&... u) {
    pr(t);
    pr(u...);
}
void ps() { pr("\n"); }  // print w/ spaces
tcTUU > void ps(const T& t, const U&... u) {
    pr(t);
    if (sizeof...(u)) pr(" ");
    ps(u...);
}

// DEBUG
void DBG() { cerr << "]" << endl; }
tcTUU > void DBG(const T& t, const U&... u) {
    cerr << ts(t);
    if (sizeof...(u)) cerr << ", ";
    DBG(u...);
}
#ifdef LOCAL  // compile with -DLOCAL, chk -> fake assert
#define dbg(...)                                                       \
    cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", \
        DBG(__VA_ARGS__)
#define chk(...)                                                        \
    if (!(__VA_ARGS__))                                                 \
        cerr << "Line(" << __LINE__ << ") -> function(" << __FUNCTION__ \
             << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")"             \
             << "\n",                                                   \
            exit(0);
#else
#define dbg(...) 0
#define chk(...) 0
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n + 1], p[n + 1];
    for (int i = 1; i <= n; i++) { cin >> a[i]; }

    set<pair<int, int>> topHigh;
    set<pair<int, int>> topLow;
    topHigh.insert({INT_MIN, -1});
    topLow.insert({INT_MAX, n});
    long long H = 0, L = 0, cH = 0, cL = 0;
    for (int i = 1; i <= n; i++) {
        int x   = a[i];
        auto p1 = topHigh.rbegin()->first;
        auto p2 = topLow.begin()->first;
        if (x < p1) {
            topHigh.insert({x, i});
            H += x;
            cH++;
        } else {
            topLow.insert({x, i});
            L += x;
            cL++;
        }

        while (topHigh.size() > 1 + topLow.size()) {
            auto x = *topHigh.rbegin();
            topHigh.erase(x);
            topLow.insert(x);
            H -= x.first;
            cH--;
            L += x.first;
            cL++;
        }

        while (topLow.size() > topHigh.size()) {
            auto x = *topLow.begin();
            topLow.erase(x);
            topHigh.insert(x);
            L -= x.first;
            cL--;
            H += x.first;
            cH++;
        }
        if (i >= k) {
            long long median = topHigh.rbegin()->first;

            long long ans = L - cL * median + median * cH - H;
            cout << ans << " ";

            auto p = topLow.find({a[i - k + 1], i - k + 1});
            if (p != topLow.end()) {
                topLow.erase(p);
                cL--;
                L -= p->first;
            }

            p = topHigh.find({a[i - k + 1], i - k + 1});
            if (p != topHigh.end()) {
                topHigh.erase(p);
                cH--;
                H -= p->first;
            }
        }
    }
}

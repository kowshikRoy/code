/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-09
 * Task: LCKDSAFE
 */

#include <bits/stdc++.h>
using namespace std;

#define LL           long long
#define Ulong        unsigned long long
#define REP(i, n)    for (long long i = 0; i < n; i++)
#define mp           make_pair
#define pb           push_back
#define all(x)       (x).begin(), (x).end()
#define PI           acos(-1.0)
#define EPS          1e-14
#define F            first
#define S            second
#define in(x)        input(x)
#define in2(x, y)    in(x), in(y)
#define in3(x, y, z) in(x), in2(y, z)
#define lc           ((n) << 1)
#define rc           ((n) << 1 | 1)
#define db(x)        cout << #x << " -> " << x << endl

template <class T> inline void input(T& x) {
    register char c = getchar();
    x               = 0;
    int neg         = 0;
    for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
        ;
    if (c == '-') {
        neg = 1;
        c   = getchar();
    }
    for (; c > 47 && c < 58; c = getchar()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
    if (neg) x = -x;
}
inline long long bigmod(long long p, long long e, long long M) {
    long long ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return ret;
}
template <class T> inline T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
template <class T> inline T modinverse(T a, T M) { return bigmod(a, M - 2, M); }

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
tcT > str ts(T v[]) {
#ifdef LOCAL
    bool fst = 1;
    str res  = "{";
    int n    = sizeof(v) / sizeof(T);
    for (int i = 0; i < n; i++) {
        T x = v[i];
        if (!fst) res += ", ";
        fst = 0;
        res += ts(x);
    }
    res += "}";
    return res;
#else
    bool fst = 1;
    str res  = "";
    int n    = sizeof(v) / sizeof(T);
    for (int i = 0; i < n; i++) {
        T x = v[i];
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

/********************************************************/

const int N  = 1e6 + 6;
const int LG = 60;
int n;
LL A[N], L[N], R[N], B[N];

LL And[N][22], Or[N][22];
int mn[N];
void initRMQ(int n, LL a[]) {
    mn[0] = -1;
    for (int i = 1; i <= n; i++)
        And[i][0] = a[i], Or[i][0] = a[i], mn[i] = mn[i / 2] + 1;
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            And[i][j] = And[i][j - 1] & And[i + (1 << (j - 1))][j - 1];
            Or[i][j]  = Or[i][j - 1] | Or[i + (1 << (j - 1))][j - 1];
        }
    }
}
LL askRMQ(int L, int R) {
    int k = mn[R - L + 1];
    LL a  = And[L][k] & And[R - (1 << k) + 1][k];
    LL o  = Or[L][k] | Or[R - (1 << k) + 1][k];
    return a ^ o;
}

int pf_one[N][60], pf_zero[N][60], sf_one[N][60], sf_zero[N][60];

LL pf_or[N], sf_or[N], pf_and[N], sf_and[N];
int main() {
    int t;
    in(t);
    while (t--) {
        in(n);
        for (int i = 1; i <= n; i++) { in(A[i]); }
        initRMQ(n, A);

        for (int i = 1; i <= n; i++) {
            int j = i - 1;
            while (j > 0 && A[j] <= A[i]) j = L[j];
            L[i] = j;
        }

        for (int i = n; i >= 1; i--) {
            int j = i + 1;
            while (j <= n && A[j] < A[i]) j = R[j];
            R[i] = j;
        }

        vector<int> ones(60, 0), zero(60, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < LG; j++) {
                pf_one[i][j]  = ones[j];
                pf_zero[i][j] = zero[j];
                if ((A[i] >> j) & 1) ones[j] = i;
                else
                    zero[j] = i;
            }
        }

        fill(ones.begin(), ones.end(), n + 1);
        fill(zero.begin(), zero.end(), n + 1);

        for (int i = n; i >= 1; i--)
            for (int j = 0; j < LG; j++) {
                sf_one[i][j]  = ones[j];
                sf_zero[i][j] = zero[j];
                if ((A[i] >> j) & 1) ones[j] = i;
                else
                    zero[j] = i;
            }

    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        if (R[i] - L[i] > 150) {
            vector<int> Left, Right;
            Left.push_back(L[i] - 1);
            Left.push_back(i);
            Right.push_back(R[i] - 1);
            Right.push_back(i);
            for (int j = 0; j < LG; j++) {
                if (pf_one[i][j] > L[i]) Left.push_back(pf_one[i][j]);
                if (pf_zero[i][j] > L[i]) Left.push_back(pf_zero[i][j]);
            }
            for (int j = 0; j < LG; j++) {
                if (sf_one[i][j] < R[i]) Right.push_back(sf_one[i][j]);
                if (sf_zero[i][j] < R[i]) Right.push_back(sf_zero[i][j]);
            }
            sort(Left.begin(), Left.end());
            sort(Right.begin(), Right.end());

            LL u = -1, pre = L[i], post = i;
            for (int p = 0, q = 0; p < Left.size(); p++) {
                while (q < Right.size() && askRMQ(Left[p], Right[q]) < A[i])
                    q++;
                if (q < Right.size()) {
                    ans += (Left[p] - pre) * (Right[q] - post);
                }
                pre = Left[p];
                if (q < Right.size()) post = Right[q];
            }

        } else {
            LL a = (1LL << 60) - 1, b = 0;
            for (int j = i; j > L[i]; j--) {
                a &= A[j];
                b |= A[j];
                pf_and[j] = a;
                pf_or[j]  = b;
            }
            a = (1LL << 60) - 1, b = 0;
            for (int j = i; j < R[i]; j++) {
                a &= A[j];
                b |= A[j];
                sf_and[j] = a;
                sf_or[j]  = b;
            }
            for (int j = L[i] + 1, k = i; j <= i; j++) {
                while (k < R[i]) {
                    LL por  = pf_or[j] | sf_or[k];
                    LL pand = pf_and[j] & sf_and[k];

                    LL q = pand ^ por;
                    if ((q) >= A[i]) break;
                    k++;
                }
                ans += R[i] - k;
            }
            for (int j = L[i] + 1, k = i; j <= i; j++) {
                while (k < R[i]) {
                    LL por  = pf_or[j] | sf_or[k];
                    LL pand = pf_and[j] & sf_and[k];

                    LL q = pand ^ por;
                    if ((q) >= A[i]) break;
                    k++;
                }
                ans += R[i] - k;
            }
        }
    
    }
    cout << ans << endl;

    return 0;
}

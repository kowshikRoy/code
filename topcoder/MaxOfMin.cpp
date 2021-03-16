
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using db = double; 
using str = string; // yay python!
 
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
 
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>; 
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;
 
#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;
 
// pairs
#define mp make_pair
#define f first
#define s second
 
#define sz(x) (int)(x).size()
 
// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
 // INPUT
#define tcTUU tcT, class ...U
tcT> void re(complex<T>& c);
tcTU> void re(pair<T,U>& p);
tcT> void re(vector<T>& v);
tcT, size_t SZ> void re(AR<T,SZ>& a);
 
tcT> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }
 
tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; }
tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
tcT> void re(vector<T>& x) { trav(a,x) re(a); }
tcT, size_t SZ> void re(AR<T,SZ>& x) { trav(a,x) re(a); }
tcT> void rv(int& n, vector<T>& x) { re(n); x.rsz(n); trav(a,x) re(a); }
 
// TO_STRING
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
    #ifdef LOCAL
        return b ? "true" : "false"; 
    #else 
        return ts((int)b);
    #endif
}
tcT> str ts(complex<T> c) { 
    stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) {
    str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
    res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
    str res = ""; F0R(i,SZ) res += char('0'+b[i]);
    return res; }
tcTU> str ts(pair<T,U> p);
tcT> str ts(T v) { // containers with begin(), end()
    #ifdef LOCAL
        bool fst = 1; str res = "{";
        for (const auto& x: v) {
            if (!fst) res += ", ";
            fst = 0; res += ts(x);
        }
        res += "}"; return res;
    #else
        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += " ";
            fst = 0; res += ts(x);
        }
        return res;
 
    #endif
}
tcTU> str ts(pair<T,U> p) {
    #ifdef LOCAL
        return "("+ts(p.f)+", "+ts(p.s)+")"; 
    #else
        return ts(p.f)+" "+ts(p.s);
    #endif
}
 
// OUTPUT
tcT> void pr(T x) { cout << ts(x); }
tcTUU> void pr(const T& t, const U&... u) { 
    pr(t); pr(u...); }
void ps() { pr("\n"); } // print w/ spaces
tcTUU> void ps(const T& t, const U&... u) { 
    pr(t); if (sizeof...(u)) pr(" "); ps(u...); }
 
 // DEBUG
void DBG() { cerr << "]" << endl; }
tcTUU> void DBG(const T& t, const U&... u) {
    cerr << ts(t); if (sizeof...(u)) cerr << ", ";
    DBG(u...); }
#ifdef LOCAL // compile with -DLOCAL, chk -> fake assert
    #define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
    #define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
         << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
    #define dbg(...) 0
    #define chk(...) 0
#endif

/**
 * Author: Repon Kumar Roy
 * Task: MaxOfMin.cpp
 */

#include <bits/stdc++.h>
using namespace std;


#define LL long long
class MaxOfMin {
public:
    vector<int> F;
    int n;
    int mod = 998244353;
    map<vector<int>,LL> dp;
    
    bool check(int p, vector<int>&out) {
        if(out.size() == 0) return true;
        int m = *max_element(out.begin(), out.end());
        int v = -1;
        for(int i = 0; i < n; i ++) {
            if(F[i] == p) {
                v = i + 1;
                break;
            }
        }
        if(v == -1) return true;
        return m < v;

    }

    LL solve(vector<int> state, int ptr) {
        if(ptr == n + 1) return 1;
        auto x = dp.find(state);
        if(x != dp.end()) return x->second;
        
        LL ret = 0;
        for(int i = 0; i < state.size(); i ++) {
            for(int j = 1; j <= state[i]; j ++) {
                vector<int> nxt = state;
                nxt[i] = j-1;
                nxt.push_back(state[i]-j);
                sort(nxt.begin(), nxt.end());
                vector<int> out;
                for(int i = 0; i < nxt.size(); i ++){
                    if(nxt[i]) out.push_back(nxt[i]);
                }
                if(check(ptr,out)) 

                ret = (ret + solve(out, ptr + 1)) % mod;

            }
        }
        return dp[state] = ret % mod;
    }

    int count(vector <int> F) {
        this->F = F;
        this->n = F.size();
        return solve({n},1);
    }
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int F[]                   = {3, 1, 1};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = MaxOfMin().count(vector <int>(F, F + (sizeof F / sizeof F[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int F[]                   = {3, 1, 3};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = MaxOfMin().count(vector <int>(F, F + (sizeof F / sizeof F[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int F[]                   = {5, 2, 2, 1, 1};
			int expected__            = 12;

			std::clock_t start__      = std::clock();
			int received__            = MaxOfMin().count(vector <int>(F, F + (sizeof F / sizeof F[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int F[]                   = {6, 5, 2, 1, 1, 1};
			int expected__            = 40;

			std::clock_t start__      = std::clock();
			int received__            = MaxOfMin().count(vector <int>(F, F + (sizeof F / sizeof F[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int F[]                   = {50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
			int expected__            = 32990492;

			std::clock_t start__      = std::clock();
			int received__            = MaxOfMin().count(vector <int>(F, F + (sizeof F / sizeof F[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int F[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MaxOfMin().count(vector <int>(F, F + (sizeof F / sizeof F[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int F[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MaxOfMin().count(vector <int>(F, F + (sizeof F / sizeof F[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int F[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MaxOfMin().count(vector <int>(F, F + (sizeof F / sizeof F[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE

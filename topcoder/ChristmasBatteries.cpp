/**
 * Author: Repon Kumar Roy
 * Task: ChristmasBatteries.cpp
 */

#include <bits/stdc++.h>
using namespace std;
#define LL long long


class ChristmasBatteries {
public:
    vector<int> V[5];
    int dp[10][5];
    int solve(int bat, int idx) {
        if(idx == 5) return 0;
        if(dp[bat][idx] != -1) return dp[bat][idx];

        int ret = 0;
        int sum = 0, tot = 0;
        for(int i = 0; i < V[idx].size(); i ++) {
            if(sum + idx <= bat) {
                tot += V[idx][i];
                sum += idx;
                ret = max(ret, tot +  solve(bat - sum , idx + 1));
            }
            else break;
        }
        ret = max(ret, solve(bat, idx + 1));
        return dp[bat][idx] = ret;

    }
    int mostFun(int B, int N, int X, int Y, int Z, int M) {
        memset(dp, - 1, sizeof dp);
        for(int i = 0; i < N; i ++) {
            V[i % 5].push_back((1LL * X * i * i + Y * i + Z) % M);
        }
        for(int i = 0; i < 5; i ++) sort(V[i].begin(), V[i].end(), greater<LL>());
        return solve(B, 0);
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
			int B                     = 0;
			int N                     = 5;
			int X                     = 1;
			int Y                     = 1;
			int Z                     = 1;
			int M                     = 1000;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int B                     = 3;
			int N                     = 5;
			int X                     = 1;
			int Y                     = 1;
			int Z                     = 1;
			int M                     = 1000;
			int expected__            = 14;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int B                     = 3;
			int N                     = 5;
			int X                     = 1;
			int Y                     = 1;
			int Z                     = 1;
			int M                     = 13;
			int expected__            = 11;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int B                     = 4;
			int N                     = 10000;
			int X                     = 123;
			int Y                     = 456;
			int Z                     = 789;
			int M                     = 1;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int B                     = 7;
			int N                     = 4;
			int X                     = 3;
			int Y                     = 5;
			int Z                     = 7;
			int M                     = 997;
			int expected__            = 100;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int B                     = 2;
			int N                     = 12345;
			int X                     = 234;
			int Y                     = 34;
			int Z                     = 5;
			int M                     = 117;
			int expected__            = 143371;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int B                     = ;
			int N                     = ;
			int X                     = ;
			int Y                     = ;
			int Z                     = ;
			int M                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int B                     = ;
			int N                     = ;
			int X                     = ;
			int Y                     = ;
			int Z                     = ;
			int M                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int B                     = ;
			int N                     = ;
			int X                     = ;
			int Y                     = ;
			int Z                     = ;
			int M                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ChristmasBatteries().mostFun(B, N, X, Y, Z, M);
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

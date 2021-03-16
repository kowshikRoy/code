/**
 * Author: Repon Kumar Roy
 * Task: SecondDiameters.cpp
 */

#include <bits/stdc++.h>
using namespace std;

class SecondDiameters {
public:
    long long getSecondDiameters(vector <int> X, vector <int> Y) {
     
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) { 
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
			int X[]                   = {0, 1, 1};
			int Y[]                   = {0, 0, 1};
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = SecondDiameters().getSecondDiameters(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int X[]                   = {0, 0, 1, 1};
			int Y[]                   = {0, 1, 0, 1};
			long long expected__      = 4;

			std::clock_t start__      = std::clock();
			long long received__      = SecondDiameters().getSecondDiameters(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int X[]                   = {0, 0, 1, 2, 2};
			int Y[]                   = {0, 10, 5, 0, 10};
			long long expected__      = 500;

			std::clock_t start__      = std::clock();
			long long received__      = SecondDiameters().getSecondDiameters(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int X[]                   = {1, 2, 3, 4, 5};
			int Y[]                   = {1, 3, 6, 10, 15};
			long long expected__      = 534;

			std::clock_t start__      = std::clock();
			long long received__      = SecondDiameters().getSecondDiameters(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int X[]                   = ;
			int Y[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = SecondDiameters().getSecondDiameters(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int X[]                   = ;
			int Y[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = SecondDiameters().getSecondDiameters(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int X[]                   = ;
			int Y[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = SecondDiameters().getSecondDiameters(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
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

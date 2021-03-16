/**
 * Author: Repon Kumar Roy
 * Task: LongestSequence.cpp
 */

#include <bits/stdc++.h>
using namespace std;

class LongestSequence {
public:
    vector<int> c;
    vector<int> vis;
    bool can(int n) {
        vis.clear();
        vis.resize(n + 1);
        queue<int> q;

        for(int x: c) {
            if(x > 0 && x <= n) vis[x] = 1, q.push(x);
        }
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int x: c) {
                if(0 <= u + x && u + x <= n && vis[u + x] == false) {
                    vis[u + x] = 1;
                    q.push(u + x);
                }
            }
        }
        return vis[0] == false;
    }



    int maxLength(vector <int> C) {
        if(all(C, 1) || all(C, -1)) return -1;
        this->c = C;
        int low = 0, high = 2000;
        while(high - low > 1) {
            int mid = (low + high)/2;
            if(can(mid)) {
                low = mid;
            }
            else high = mid;
        }
        return low;
    }
    bool all(vector<int>a, int s) {
        for(auto x: a) {
            if((x > 0) != (s > 0)) return false;
        }
        return true;
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
			int C[]                   = {-2,3};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = LongestSequence().maxLength(vector <int>(C, C + (sizeof C / sizeof C[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int C[]                   = {524};
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = LongestSequence().maxLength(vector <int>(C, C + (sizeof C / sizeof C[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int C[]                   = {1, -1};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = LongestSequence().maxLength(vector <int>(C, C + (sizeof C / sizeof C[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int C[]                   = {11,-7};
			int expected__            = 16;

			std::clock_t start__      = std::clock();
			int received__            = LongestSequence().maxLength(vector <int>(C, C + (sizeof C / sizeof C[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int C[]                   = {-227,690,590,-524};
			int expected__            = 713;

			std::clock_t start__      = std::clock();
			int received__            = LongestSequence().maxLength(vector <int>(C, C + (sizeof C / sizeof C[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int C[]                   = {1000, -999};
			int expected__            = 1997;

			std::clock_t start__      = std::clock();
			int received__            = LongestSequence().maxLength(vector <int>(C, C + (sizeof C / sizeof C[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 6: {
			int C[]                   ={538, 512, -726, 702, 686, 547};
			int expected__            = 1025;

			std::clock_t start__      = std::clock();
			int received__            = LongestSequence().maxLength(vector <int>(C, C + (sizeof C / sizeof C[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			int C[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LongestSequence().maxLength(vector <int>(C, C + (sizeof C / sizeof C[0])));
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

/**
 * Author: Repon Kumar Roy
 * Task: SlotMachineHacking.cpp
 */

#include <bits/stdc++.h>
using namespace std;



class SlotMachineHacking {
public:
    int win(vector <string> reels, vector <int> steps) {
        vector<int> pos;
        int n = (int)reels.size();
        int maxRot = 1;
        for(int i = 0; i < n; i ++) {
            maxRot = reels[i].size() * maxRot;
            for(int j = 0; j < reels[i].size(); j ++) {
                if(reels[i][j] == 'c') {
                    pos.push_back(j);
                    break;
                }
            }
        }

        int result = 0;
        while(maxRot --) {
            for(int i = 0; i < n; i ++) {
                int cur = pos[i];
                int L = reels[i].length();
                int next = (cur - steps[i] % L + L ) % L;
                pos[i] = next;
            }

            bool flag = true;
            for(int i = 0; i < n; i ++) {
                if(pos[i]) flag = false;
            }

            if(flag) {
                return result;
            }
            result ++;
        }
        return -1;
     
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
			string reels[]            = {"abc", "acb", "cab"};
			int steps[]               = {32, 31, 30};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = SlotMachineHacking().win(vector <string>(reels, reels + (sizeof reels / sizeof reels[0])), vector <int>(steps, steps + (sizeof steps / sizeof steps[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string reels[]            = {"abc", "acb", "cab"};
			int steps[]               = {30, 33, 300000006};
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = SlotMachineHacking().win(vector <string>(reels, reels + (sizeof reels / sizeof reels[0])), vector <int>(steps, steps + (sizeof steps / sizeof steps[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string reels[]            = {"abc", "bac", "abpc"};
			int steps[]               = {1, 1, 1};
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = SlotMachineHacking().win(vector <string>(reels, reels + (sizeof reels / sizeof reels[0])), vector <int>(steps, steps + (sizeof steps / sizeof steps[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string reels[]            = {"aac", "aac", "aaac"};
			int steps[]               = {1, 1, 1};
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = SlotMachineHacking().win(vector <string>(reels, reels + (sizeof reels / sizeof reels[0])), vector <int>(steps, steps + (sizeof steps / sizeof steps[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string reels[]            = {"c", "c", "ababcbabab", "c"};
			int steps[]               = {470, 4700, 47002, 470000};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = SlotMachineHacking().win(vector <string>(reels, reels + (sizeof reels / sizeof reels[0])), vector <int>(steps, steps + (sizeof steps / sizeof steps[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string reels[]            = {"ca", "caba"};
			int steps[]               = {1, 2};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = SlotMachineHacking().win(vector <string>(reels, reels + (sizeof reels / sizeof reels[0])), vector <int>(steps, steps + (sizeof steps / sizeof steps[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases
/*
      case 6: {
			string reels[]            = ;
			int steps[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SlotMachineHacking().win(vector <string>(reels, reels + (sizeof reels / sizeof reels[0])), vector <int>(steps, steps + (sizeof steps / sizeof steps[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string reels[]            = ;
			int steps[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SlotMachineHacking().win(vector <string>(reels, reels + (sizeof reels / sizeof reels[0])), vector <int>(steps, steps + (sizeof steps / sizeof steps[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string reels[]            = ;
			int steps[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SlotMachineHacking().win(vector <string>(reels, reels + (sizeof reels / sizeof reels[0])), vector <int>(steps, steps + (sizeof steps / sizeof steps[0])));
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

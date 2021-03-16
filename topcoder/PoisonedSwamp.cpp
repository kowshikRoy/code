/**
 * Author: Repon Kumar Roy
 * Task: PoisonedSwamp.cpp
 */

#include <bits/stdc++.h>
using namespace std;

class PoisonedSwamp {
public:
    string cross(vector <string> g) {
        int r = g.size(), c = g[0].size();
        int dp[r][c][10], dp2[r][c][10];
        int dir[][2]= {{0,1},{0,-1},{1,0},{-1,0}};
        memset(dp, 0, sizeof dp);
        memset(dp2, 0, sizeof dp);
        dp[0][0][0] = 1;
        for(int step = 0; step <= r * c; step ++) {
            for(int i = 0; i < r; i ++) {
                for(int j = 0; j < c; j ++) {
                    if(g[i][j] == '#') continue;
                    int v = 0;
                    if(g[i][j] == '.') v = 0;
                    else if(g[i][j] == 'S') v = -100;
                    else v = g[i][j] - '0';
                    for(int k = 0; k < 10; k ++) {
                        for(int d = 0; d < 4; d ++) {
                            int x = i + dir[d][0], y = j + dir[d][1];
                            if(x >= 0 && x < r && y >= 0 && y < c && dp[x][y][k]) {
                                if(k + v < 10) {
                                    int newP = max(0, k + v);
                                    dp2[i][j][newP] = 1;
                                }
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < r; i ++) {
                for(int j = 0; j < c; j ++) {
                    for(int k = 0; k < 10; k ++) dp[i][j][k] = dp2[i][j][k];
                }
            }
            memset(dp2,0,sizeof dp2);
            for(int k = 0; k < 10; k ++) {
                if(dp[r-1][c-1][k]) return "possible";
            }
        }

        return "impossible";

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
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
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
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string swamp[]            = {".....",
 "####.",
 ".....",
 ".####",
 "....."};
			string expected__         = "possible";

			std::clock_t start__      = std::clock();
			string received__         = PoisonedSwamp().cross(vector <string>(swamp, swamp + (sizeof swamp / sizeof swamp[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string swamp[]            = {".....",
 "####.",
 "97...",
 "9#2##",
 "97..."};
			string expected__         = "possible";

			std::clock_t start__      = std::clock();
			string received__         = PoisonedSwamp().cross(vector <string>(swamp, swamp + (sizeof swamp / sizeof swamp[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string swamp[]            = {".111111111.",
 ".#########.",
 "..22222...."};
			string expected__         = "possible";

			std::clock_t start__      = std::clock();
			string received__         = PoisonedSwamp().cross(vector <string>(swamp, swamp + (sizeof swamp / sizeof swamp[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string swamp[]            = {".#222#111",
 "4#S#2#1#S",
 "4#3#S#1#9",
 "S33#111#."};
			string expected__         = "possible";

			std::clock_t start__      = std::clock();
			string received__         = PoisonedSwamp().cross(vector <string>(swamp, swamp + (sizeof swamp / sizeof swamp[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string swamp[]            = {"..111111111111..",
 "###############."};
			string expected__         = "impossible";

			std::clock_t start__      = std::clock();
			string received__         = PoisonedSwamp().cross(vector <string>(swamp, swamp + (sizeof swamp / sizeof swamp[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string swamp[]            = {"..111111111111..",
 "#######S#######."};
			string expected__         = "possible";

			std::clock_t start__      = std::clock();
			string received__         = PoisonedSwamp().cross(vector <string>(swamp, swamp + (sizeof swamp / sizeof swamp[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string swamp[]            = {"..#.#.",
 "..#.#.",
 "#5#.5.",
 "....#."};
			string expected__         = "impossible";

			std::clock_t start__      = std::clock();
			string received__         = PoisonedSwamp().cross(vector <string>(swamp, swamp + (sizeof swamp / sizeof swamp[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			string swamp[]            = {".1.#.",
 ".9.#.",
 ".###.",
 "2#.1.",
 ".#.7."};
			string expected__         = "impossible";

			std::clock_t start__      = std::clock();
			string received__         = PoisonedSwamp().cross(vector <string>(swamp, swamp + (sizeof swamp / sizeof swamp[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			string swamp[]            = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = PoisonedSwamp().cross(vector <string>(swamp, swamp + (sizeof swamp / sizeof swamp[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string swamp[]            = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = PoisonedSwamp().cross(vector <string>(swamp, swamp + (sizeof swamp / sizeof swamp[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			string swamp[]            = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = PoisonedSwamp().cross(vector <string>(swamp, swamp + (sizeof swamp / sizeof swamp[0])));
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

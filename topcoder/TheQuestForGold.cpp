/**
 * Author: Repon Kumar Roy
 * Task: TheQuestForGold.cpp
 */

#include <bits/stdc++.h>
using namespace std;

class TheQuestForGold {
public:
    string explore(vector <string> cave) {
        int n = (int)cave.size(), m = cave[0].size();
        int cnt = 0;
        vector<vector<int>> g(n, vector<int>(m,0));
        int X, Y;
        int dir[][2] = {{0,1}, {0,-1},{1,0},{-1,0}};
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                if(cave[i][j] == 'T') cnt ++;
                if(cave[i][j] == 'S') {
                    X = i;
                    Y = j;
                }
                if(cave[i][j] == 'P') {
                    g[i][j] = 1;
                    for(int d = 0; d < 4; d ++) {
                        int x = i + dir[d][0], y = j + dir[d][1];
                        if(x >= 0 && x < n && y >= 0 && y < m) {
                            g[x][y] = 1;
                        }
                    }
                }
            }
        }
        if(cnt == 0) return "no gold";
        queue<pair<int,int>> q;
        q.push({X,Y});
        vector<vector<int>> vis(n, vector<int>(m,0));
        vis[X][Y] = 1;

        while(!q.empty()) {
            auto u = q.front(); q.pop();
            int i = u.first, j = u.second;
            if(cave[i][j] == 'T') return "gold";
            if(g[i][j] == 1) continue;
            for(int d = 0; d < 4; d ++) {
                int x = i + dir[d][0], y = j + dir[d][1];
                if(x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0) {
                   vis[x][y] = 1;
                   q.push({x,y});
                }
            }
        }
        return "no gold";
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
			string cave[]             = {"S....",
 ".....",
 "...T.",
 "....."};
			string expected__         = "gold";

			std::clock_t start__      = std::clock();
			string received__         = TheQuestForGold().explore(vector <string>(cave, cave + (sizeof cave / sizeof cave[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string cave[]             = {"S....",
 "...P.",
 "..PTP",
 "...P."};
			string expected__         = "no gold";

			std::clock_t start__      = std::clock();
			string received__         = TheQuestForGold().explore(vector <string>(cave, cave + (sizeof cave / sizeof cave[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string cave[]             = {"S....",
 "..P.P",
 ".P.T.",
 "....."};
			string expected__         = "no gold";

			std::clock_t start__      = std::clock();
			string received__         = TheQuestForGold().explore(vector <string>(cave, cave + (sizeof cave / sizeof cave[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string cave[]             = {"S....",
 "P....",
 "...T.",
 "....."};
			string expected__         = "no gold";

			std::clock_t start__      = std::clock();
			string received__         = TheQuestForGold().explore(vector <string>(cave, cave + (sizeof cave / sizeof cave[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string cave[]             = {"S....",
 ".....",
 "PPP..",
 ".....",
 ".....",
 ".....",
 "..PPP",
 "..T.."}
;
			string expected__         = "gold";

			std::clock_t start__      = std::clock();
			string received__         = TheQuestForGold().explore(vector <string>(cave, cave + (sizeof cave / sizeof cave[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string cave[]             = {".......",
 ".......",
 "..P.P..",
 "..PPP..",
 "..P.P..",
 ".......",
 "..S...."};
			string expected__         = "no gold";

			std::clock_t start__      = std::clock();
			string received__         = TheQuestForGold().explore(vector <string>(cave, cave + (sizeof cave / sizeof cave[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string cave[]             = {".......",
 ".......",
 "..P.P..",
 "..PTP..",
 "..P.P..",
 ".......",
 "..S...."};
			string expected__         = "no gold";

			std::clock_t start__      = std::clock();
			string received__         = TheQuestForGold().explore(vector <string>(cave, cave + (sizeof cave / sizeof cave[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string cave[]             = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = TheQuestForGold().explore(vector <string>(cave, cave + (sizeof cave / sizeof cave[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string cave[]             = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = TheQuestForGold().explore(vector <string>(cave, cave + (sizeof cave / sizeof cave[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string cave[]             = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = TheQuestForGold().explore(vector <string>(cave, cave + (sizeof cave / sizeof cave[0])));
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

/**
 * Author: Repon Kumar Roy
 * Task: BinaryCode.cpp
 */

#include <bits/stdc++.h>
using namespace std;

class BinaryCode {
public:
    vector <string> decode(string message) {
        vector<string> ret;
        int n = (int) message.size();

        auto get = [&](string s, int idx) {
            if(idx < 0) return 0;
            return s[idx] - '0';
        };
        for(int i = 0; i < 2; i ++) {
            string p = message;
            p[0] = i + '0';
            bool flag = true;
            for(int j = 1; j < message.size(); j ++) {
                int v = get(message, j - 1) - get(p, j - 2) - get(p, j - 1); 
                if(v < 0 || v > 1) {
                    flag = false;
                }
                p[j] = v + '0';
            }
            if(get(message, n-1) != get(p, n-1) + get(p, n-2)) flag = false;
            if(flag) ret.push_back(p);
            else ret.push_back("NONE");
        }
        return ret;
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
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }
	template<> std::ostream& operator<<(std::ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, std::clock_t elapsed) { 
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
			string message            = "123210122";
			string expected__[]       = { "011100011",  "NONE" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = BinaryCode().decode(message);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string message            = "11";
			string expected__[]       = { "01",  "10" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = BinaryCode().decode(message);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string message            = "22111";
			string expected__[]       = { "NONE",  "11001" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = BinaryCode().decode(message);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string message            = "123210120";
			string expected__[]       = { "NONE",  "NONE" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = BinaryCode().decode(message);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			string message            = "3";
			string expected__[]       = { "NONE",  "NONE" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = BinaryCode().decode(message);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			string message            = "12221112222221112221111111112221111";
			string expected__[]       = { "01101001101101001101001001001101001",  "10110010110110010110010010010110010" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = BinaryCode().decode(message);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string message            = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = BinaryCode().decode(message);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			string message            = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = BinaryCode().decode(message);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			string message            = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = BinaryCode().decode(message);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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

/**
 * Author: Repon Kumar Roy
 * Task: MaximumPenalty.cpp
 */

#include <bits/stdc++.h>
using namespace std;

#define LL unsigned long long
class MaximumPenalty {
   public:
    LL calc(LL t, vector<int> P) {
        LL ans = 0;
        LL m   = 1;
        for (int i = 0; i < 4; i++) {
            ans += P[i] * m;
            m *= t;
        }
        return ans;
    }

    vector<int> L, P;
    int n;

    pair<bool, vector<int>> can(LL p) {
        vector<int> A(n);
        vector<LL> Time(n);
        LL tot = 0;
        for (int i = 0; i < n; i++) A[i] = i, tot += L[i];
        for (int i = 0; i < n; i++) {
            int pivot = -1;
            for (int j = 0; j < n - i; j++) {
                int id = A[j];
                if (calc(tot, {P[4 * id], P[4 * id + 1], P[4 * id + 2],
                               P[4 * id + 3]}) <= p) {
                    pivot = j;
                    break;
                }
            }
            if (pivot == -1) return {false, {}};
            swap(A[pivot], A[n - 1 - i]);
            tot -= L[A[n - 1 - i]];
        }

        return {true, A};
    }

    vector<int> schedule(vector<int> L, vector<int> P) {
        this->L = L;
        this->P = P;
        this->n = (int)L.size();
        vector<int> ans;
        LL low = 0, high = calc(100000, {8000, 8000, 8000, 8000}) + 1;
        while (low < high) {
            auto mid = low + (high - low) / 2;
            auto v   = can(mid);
            if (v.first) {
                ans  = v.second;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
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
                std::cerr << "Illegal input! Test case " << casenum
                          << " does not exist." << std::endl;
            }
            return;
        }

        int correct = 0, total = 0;
        for (int i = 0;; ++i) {
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
            std::cerr << "Some cases FAILED (passed " << correct << " of "
                      << total << ")." << std::endl;
        } else {
            std::cerr << "All " << total << " tests passed!" << std::endl;
        }
    }

    template <typename T>
    std::ostream &operator<<(std::ostream &os, const vector<T> &v) {
        os << "{";
        for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end();
             ++vi) {
            if (vi != v.begin()) os << ",";
            os << " " << *vi;
        }
        os << " }";
        return os;
    }

    int verify_case(int casenum, const vector<int> &expected,
                    const vector<int> &received, std::clock_t elapsed) {
        std::cerr << "Example " << casenum << "... ";

        string verdict;
        vector<string> info;
        char buf[100];

        if (elapsed > CLOCKS_PER_SEC / 200) {
            std::sprintf(buf, "time %.2fs", elapsed * (1.0 / CLOCKS_PER_SEC));
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
            for (size_t i = 0; i < info.size(); ++i) {
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
                int L[]          = {7, 4, 1};
                int P[]          = {0, 0, 0, 1, 0, 0, 2, 0, 0, 3, 0, 0};
                int expected__[] = {0, 2, 1};

                std::clock_t start__   = std::clock();
                vector<int> received__ = MaximumPenalty().schedule(
                    vector<int>(L, L + (sizeof L / sizeof L[0])),
                    vector<int>(P, P + (sizeof P / sizeof P[0])));
                return verify_case(
                    casenum__,
                    vector<int>(expected__,
                                expected__ +
                                    (sizeof expected__ / sizeof expected__[0])),
                    received__, clock() - start__);
            }
            case 1: {
                int L[] = {7, 4, 2, 5};
                int P[] = {47, 0, 0, 0, 47, 0, 0, 0, 47, 0, 0, 0, 47, 0, 0, 0};
                int expected__[] = {3, 2, 1, 0};

                std::clock_t start__   = std::clock();
                vector<int> received__ = MaximumPenalty().schedule(
                    vector<int>(L, L + (sizeof L / sizeof L[0])),
                    vector<int>(P, P + (sizeof P / sizeof P[0])));
                return verify_case(
                    casenum__,
                    vector<int>(expected__,
                                expected__ +
                                    (sizeof expected__ / sizeof expected__[0])),
                    received__, clock() - start__);
            }
            case 2: {
                int L[] = {7, 4, 2, 5};
                int P[] = {0, 47, 0, 0, 0, 47, 0, 0, 0, 47, 0, 0, 0, 47, 0, 0};
                int expected__[] = {3, 2, 1, 0};

                std::clock_t start__   = std::clock();
                vector<int> received__ = MaximumPenalty().schedule(
                    vector<int>(L, L + (sizeof L / sizeof L[0])),
                    vector<int>(P, P + (sizeof P / sizeof P[0])));
                return verify_case(
                    casenum__,
                    vector<int>(expected__,
                                expected__ +
                                    (sizeof expected__ / sizeof expected__[0])),
                    received__, clock() - start__);
            }
            case 3: {
                int L[]          = {7, 4, 2, 5};
                int P[]          = {0, 7, 8,  15, 1, 6, 9,  14,
                           2, 5, 10, 13, 3, 4, 11, 12};
                int expected__[] = {0, 1, 2, 3};

                std::clock_t start__   = std::clock();
                vector<int> received__ = MaximumPenalty().schedule(
                    vector<int>(L, L + (sizeof L / sizeof L[0])),
                    vector<int>(P, P + (sizeof P / sizeof P[0])));
                return verify_case(
                    casenum__,
                    vector<int>(expected__,
                                expected__ +
                                    (sizeof expected__ / sizeof expected__[0])),
                    received__, clock() - start__);
            }

                // custom cases

                /*      case 4: {
                                        int L[]                   = ;
                                        int P[]                   = ;
                                        int expected__[]          = ;

                                        std::clock_t start__      =
                   std::clock(); vector <int> received__   =
                   MaximumPenalty().schedule(vector <int>(L, L + (sizeof L /
                   sizeof L[0])), vector <int>(P, P + (sizeof P / sizeof
                   P[0]))); return verify_case(casenum__, vector
                   <int>(expected__, expected__ + (sizeof expected__ / sizeof
                   expected__[0])), received__, clock()-start__);
                                }*/
                /*      case 5: {
                                        int L[]                   = ;
                                        int P[]                   = ;
                                        int expected__[]          = ;

                                        std::clock_t start__      =
                   std::clock(); vector <int> received__   =
                   MaximumPenalty().schedule(vector <int>(L, L + (sizeof L /
                   sizeof L[0])), vector <int>(P, P + (sizeof P / sizeof
                   P[0]))); return verify_case(casenum__, vector
                   <int>(expected__, expected__ + (sizeof expected__ / sizeof
                   expected__[0])), received__, clock()-start__);
                                }*/
                /*      case 6: {
                                        int L[]                   = ;
                                        int P[]                   = ;
                                        int expected__[]          = ;

                                        std::clock_t start__      =
                   std::clock(); vector <int> received__   =
                   MaximumPenalty().schedule(vector <int>(L, L + (sizeof L /
                   sizeof L[0])), vector <int>(P, P + (sizeof P / sizeof
                   P[0]))); return verify_case(casenum__, vector
                   <int>(expected__, expected__ + (sizeof expected__ / sizeof
                   expected__[0])), received__, clock()-start__);
                                }*/
            default: return -1;
        }
    }
}  // namespace moj_harness

#include <cstdlib>
int main(int argc, char *argv[]) {
    if (argc == 1) {
        moj_harness::run_test();
    } else {
        for (int i = 1; i < argc; ++i)
            moj_harness::run_test(std::atoi(argv[i]));
    }
}
// END CUT HERE

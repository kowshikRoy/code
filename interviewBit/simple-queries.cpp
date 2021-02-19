#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int N = 10001;
const int mod = 1e9 + 7;
vector<int> srlve(vector<int> &a, vector<int> &b) {
    int n = (int)a.size();
    vector<long long> sum(N, 1);
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i) sum[j] = (sum[j] * i) % mod;

    vector<int> L(n, -1), R(n, n);
    for (int i = 0; i < n; i++) {
        int j = i - 1;
        while (j >= 0 && a[j] <= a[i]) j = L[j];
        L[i] = j;
    }

    for (int i = n - 1; i >= 0; i--) {
        int j = i + 1;
        while (j < n && a[j] < a[i]) j = R[j];
        R[i] = j;
    }
    // for(auto a: L)cout << a << " "; cout << endl;
    // for(auto a: R)cout << a << " "; cout << endl;
    map<long long, long long> H;
    for (int i = 0; i < n; i++) {
        long long l = i - L[i], r = R[i] - i;
        H[sum[a[i]]] += r * l;
    }

    vector<long long> A, C, P;
    for (auto it = H.rbegin(); it != H.rend(); it++) {
        A.push_back(it->first);
        C.push_back(it->second);
        P.push_back(it->second + (P.size() ? P.back() : 0));
    }
    // for(auto a: A)cout << a << " "; cout << endl;
    // for(auto a: C)cout << a << " "; cout << endl;
    // for(auto a: P)cout << a << " "; cout << endl;

    vector<int> res;
    for (int i = 0; i < (int)b.size(); i++) {
        int k = b[i];
        auto it = lower_bound(P.begin(), P.end(), k) - P.begin();
        res.push_back((int)A[it]);
    }
    return res;
}

int main() {}

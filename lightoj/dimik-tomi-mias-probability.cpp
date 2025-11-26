#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

long long Fact(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) { res *= i; }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    for (int cs = 1; cs <= t; cs++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string word;
        map<string, int> m;
        long long result = 1;
        int n            = 0;
        while (ss >> word) {
            m[word]++;
            n++;
        }
        result = Fact(n);
        for (auto x : m) { result /= Fact(x.second); }

        printf("1/%lld\n", result);
    }
}

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minOperations' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

long minOperations(long n) {
    // 1 -> 0: 1
    // 10 -> (110, 11) -> (111, 01) -> (101,0) : 3
    // For 2^n number, apply 2 operation first
    // 100 -> 101->111->110->010 .. : 7
    // 2^2 = 2^3 - 1

    // 1011 -> make 011 -> 0 and then 1000-> known
    cout << n << endl;
    if (n == 0) return 0;

    int k       = 0;
    long long t = n;
    while (t) k++,
    t /= 2;

    long long rm = n ^ (1LL << (k -1));
    cout<<rm<<endl;

    return ((1LL << k) - 1) - minOperations(rm);
}
int main() {
    long long n;
    cin>>n;
    cout<< minOperations(n) << endl;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

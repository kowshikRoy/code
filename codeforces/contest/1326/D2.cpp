#include <bits/stdc++.h>
using namespace std;

int B         = 31;
int B2        = 37;
const int MOD = 1e9 + 9;
const int mod = 1e9 + 7;
string findMax(string &s) {
    long long h1 = 0, h2 = 0;
    long long h3 = 0, h4 = 0;
    long long M  = 1;
    long long M2 = 1;
    int pivot    = 0;
    for (int i = 0; i < s.size(); i++) {
        h1 = (h1 * B + s[i] - 'a') % MOD;
        h3 = (h3 * B2 + s[i] - 'a') % mod;
        h2 = (h2 + (s[i] - 'a') * M) % MOD;
        h4 = (h4 + (s[i] - 'a') * M2) % mod;
        M  = (B * M) % MOD;
        M2 = (B2 * M2) % mod;
        if (h1 == h2 && h3 == h4) { pivot = i; }
    }
    return s.substr(0, pivot + 1);
}

string findMax(string &s, int i, int j) {
    string slice = s.substr(i, j - i + 1);
    string a     = findMax(slice);
    reverse(slice.begin(), slice.end());
    string b = findMax(slice);
    return a.size() > b.size() ? a : b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int i = 0, j = s.size() - 1;
        while (i <= j && s[i] == s[j]) i++, j--;
        if (i > j) {
            cout << s << endl;
            continue;
        }

        cout << s.substr(0, i);
        cout << findMax(s, i, j);
        cout << s.substr(j + 1);
        cout << endl;
    }
    return 0;
}

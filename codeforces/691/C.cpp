#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    while (s.size() && s.back() == '0') s.pop_back();
    if (s.size() == 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '0') {
            pivot = i;
            break;
        }
    }
    s = s.substr(pivot);
        for(int i = 0; i < s.size( q

	for(int i = 0; i < s.size(); i ++) {
        if (s[i] == '.') { return 0; }

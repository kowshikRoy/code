#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;

bool isOk(array<int,26> text, array<int,26> p) {
    for(int i = 0; i < 26; i++) {
        if(p[i] > text[i]) return false;
    }
    return true;
}

void solve(int cs) {
    cout << "Case " << cs << ":" << endl;
    int n;
    cin >> n;
    vector<array<int,26>> words(n);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(auto c: s) words[i][c-'a']++;
    }
    int q;
    cin >> q;
    while(q--) {
        string s;
        int cnt = 0;
        array<int,26> text = {0};
        
        cin >> s;
        for(auto c: s) text[c-'a']++;
        for(int i = 0; i < n; i++) {
            if(isOk(text, words[i])) cnt++;
        }
        cout << cnt << endl;
    }
}

int main() {
    int cs = 0;
    cin >> cs;
    for(int t = 1; t <= cs; t++) solve(t);
}

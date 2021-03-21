#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    set<char> st;
    st.insert('A');
    st.insert('H');
    st.insert('I');
    st.insert('M');
    st.insert('O');
    st.insert('T');
    st.insert('U');
    st.insert('V');
    st.insert('W');
    st.insert('X');
    st.insert('Y');
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[s.size() - 1 - i] || st.find(s[i]) == st.end()) {
            puts("NO\n");
            return 0;
        }
    }
    puts("YES\n");

    return 0;
}

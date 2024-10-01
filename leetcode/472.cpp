/**
 * Author: Repon Kumar Roy
 * Date: 2021-08-20
 * Task: 472
 */

#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
    os << '{';
    string sep;
    for (const T &x : v) os << sep << x, sep = ", ";
    return os << '}';
}

void dbg_out() { cerr << "]" << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
    cerr << H;
    if (sizeof...(T)) cerr << ", ";
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...)                                                       \
    cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", \
        dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

using namespace std;

class Solution {
private:
    vector<vector<int>> T;
    vector<int> is_word;
    vector<int> vis;
    void insert(string &s) {
        int cur = 0;
        for (auto c : s) {
            int v = c - 'a';
            if (T[cur][v] == -1) {
                T[cur][v] = T.size();
                T.push_back(vector<int>(26, -1));
            }
            cur = T[cur][v];
        }
        while (is_word.size() <= cur) is_word.push_back(0);
        is_word[cur] = 1;
    }

    bool dfs(string &s, int pos) {
        if (pos == s.length()) return true;
        if (vis[pos]) return false;
        vis[pos] = true;
        dbg(pos);

        int cur = 0;
        for (int i = pos; i < s.size(); i++) {
            int v = s[i] - 'a';
            if (T[cur][v] == -1) return false;
            cur = T[cur][v];
            if (is_word[cur] && dfs(s, i + 1)) return true;
        }
        return false;
    }

public:
    Solution() {
        T.push_back(vector<int>(26, -1));
        vis.resize(1004, 0);
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        sort(words.begin(), words.end(),
             [](string &a, string &b) { return a.length() < b.length(); });

        vector<string> ans;
        for (string s : words) {
            int len = s.size();
            fill(vis.begin(), vis.begin() + len, 0);
            if (dfs(s, 0)) ans.push_back(s);
            else
                insert(s);
        }

        return ans;
    }
};
int main() {
    vector<string> words = {"cat", "cats",        "catsdogcats",
                            "dog", "dogcatsdog",  "hippopotamuses",
                            "rat", "ratcatdogcat"};
    dbg(Solution().findAllConcatenatedWordsInADict(words));
}

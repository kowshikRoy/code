#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, bool> answer;
struct rect {
    long long p, q, idx;
    long long eval(long long x) { return p * x + q; }
};

bool bad(rect a, rect b, rect c) {
    return (c.q - a.q) * (b.p - a.p) >= (b.q - a.q) * (c.p - a.p);
}
struct cht {
    int beg;
    vector<rect> ch;

    void insert(rect r) {
        while (ch.size() >= 2 && bad(ch[ch.size() - 2], ch.back(), r))
            ch.pop_back();

        while (!ch.empty() && ch.back().p == r.p) ch.pop_back();

        ch.push_back(r);
    }

    answer eval(long long x) {
        if (beg == ch.size()) return {0, false};

        while (beg + 1 < ch.size() && ch[beg + 1].eval(x) >= ch[beg].eval(x))
            ++beg;

        return {ch[beg].eval(x), true};
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

pair<int, int> p[2505];
int main() {
    int n;
    cin >> n;
    vector<int> xs, ys;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
        xs.push_back(p[i].first);
        ys.push_back(p[i].second);
    }
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

    sort(ys.begin(), ys.end());
    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());

    for (int i = 0; i < n; i++)
        p[i].first =
            lower_bound(xs.begin(), xs.end(), p[i].first) - xs.begin() + 1;
    for (int i = 0; i < n; i++)
        p[i].second =
            lower_bound(ys.begin(), ys.end(), p[i].second) - ys.begin() + 1;

    long long ans = 0;

    for (int x1 = 0; x1 <= xs.size(); x1++) {
        for (int x2 = x1 + 1; x2 <= xs.size(); x2++) {
            for (int y1 = 0; y1 <= ys.size(); y1++) {
                for (int y2 = y1 + 1; y2 <= ys.size(); y2++) {
                    int cnt = 0;
                    for (int i = 0; i < n; i++) {
                        if (p[i].first < x1 || p[i].first > x2 ||
                            p[i].second < y1 || p[i].second > y2)
                            continue;
                        if (p[i].first == x1) cnt++;
                        if (p[i].first == x2) cnt++;
                        if (p[i].second == y1) cnt++;
                        if (p[i].second == y2) cnt++;
                    }
                    if (cnt == 4) { ans++; }
                }
            }
        }
    }

    cout << ans + n + 1 << endl;
}

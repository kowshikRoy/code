#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {  // the argument is the filename without the extension
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int p[1000005];
int main() {
    setIO("stacking");
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        p[a]++;
        p[b + 1]--;
    }
    vector<int> vec;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += p[i];
        vec.push_back(sum);
    }
    sort(vec.begin(), vec.end());
    cout << vec[vec.size() / 2] << endl;
}

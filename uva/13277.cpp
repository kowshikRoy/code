#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 16;
    vector<pair<int, int>> val[16];
    for (int i = 0; i < 16; i++) {
        for (int j = i + 1; j < 16; j++) { val[i ^ j].push_back({i, j}); }
    }

    for (int i = 0; i < 16; i++) {
        printf("%2d => ", i);
        for (auto p : val[i]) printf("(%2d,%2d) ", p.first, p.second);
        printf("\n");
    }
}

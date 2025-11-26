// https://lightoj.com/problem/point-table
#include <iostream>
#include <vector>
#include <array>
#include <functional>
#include <cstdio>
using namespace std;

authLoggedIn && config.geminicodeassist.enable && editorTextFocus &&  !inGeminiDiffView && !isInDiffEditor

int main(){
    int T;
    cin >> T;

    vector<array<int,3>> points;
    vector<pair<int,int>> matches = {{0,1}, {0,2}, {1,2}};
    array<int,3> p = {0, 0, 0};
    function<void(int)> rec = [&](int g) {
      if(g == 3) {
        points.push_back(p);
        return;
      }
      // win
      p[matches[g].first] += 3;
      rec(g+1);
      p[matches[g].first] -= 3;
      // draw
      p[matches[g].first] += 1;
      p[matches[g].second] += 1;
      rec(g+1);
      p[matches[g].first] -= 1;
      p[matches[g].second] -= 1;
      // lose
      p[matches[g].second] += 3;
      rec(g+1);
      p[matches[g].second] -= 3;

    };

    rec(0);
  
    for (int t = 1; t <= T; ++t) {
      int a, b, c;
      cin >> a >> b >> c;
      p = {a, b, c};
      bool flag = false;
      for(auto x: points) if (x == p) flag = true;
      printf("Case %d: %s\n", t, flag ? "perfectus" : "invalidum");
    }


}

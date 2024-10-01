/**
 * Author: Repon Kumar Roy
 * Date: Unable to find executable tmp directory, check noexec on /tmp
 * Task: 790
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

struct submission {
  char p, s;
  int h, m;
};

int main() {
  int t;
  string str;
  cin >> t;
  getline(cin, str);
  getchar();
  while (t--) {
    vector<submission> subs[26];

    int solved_count[26] = {0};
    int score[26] = {0};
    int max_t = 0;

    while (getline(cin, str)) {
      if (str.empty()) break;
      int t, h, m;
      char p, s;
      sscanf(str.c_str(), "%d %c %d:%d %c", &t, &p, &h, &m, &s);
      subs[t].push_back({p, s, h, m});
      max_t = max(max_t, t);
    }
    for (int i = 1; i <= max_t; i++) {
      if (subs[i].size() == 0) continue;
      sort(subs[i].begin(), subs[i].end(), [](submission& a, submission& b) {
        if (a.h * 60 + a.m == b.h * 60 + b.m) return a.s == 'N';
        return a.h * 60 + a.m < b.h * 60 + b.m;
      });
      int total_solved = 0;
      int total_time = 0;
      map<char, int> failed;
      set<int> accepted;
      for (auto s : subs[i]) {
        if (accepted.count(s.p)) continue;
        if (s.s == 'Y') {
          accepted.insert(s.p);
          total_solved++;
          total_time += s.h * 60 + s.m;
          if (failed.count(s.p)) total_time += failed[s.p] * 20;
        } else {
          failed[s.p]++;
        }
      }
      solved_count[i] = total_solved;
      score[i] = total_time;
    }

    vector<int> ts;
    for (int i = 1; i <= max_t; i++) ts.push_back(i);
    sort(ts.begin(), ts.end(), [&](int a, int b) {
      if (solved_count[a] == solved_count[b]) {
        if (score[a] == score[b]) return a < b;
        return score[a] < score[b];
      }
      return solved_count[a] > solved_count[b];
    });
    int ranks[26];
    printf("RANK TEAM PRO/SOLVED TIME\n");
    for (int i = 0; i < ts.size(); i++) {
      if (i > 0 && solved_count[ts[i - 1]] == solved_count[ts[i]] &&
          score[ts[i - 1]] == score[ts[i]])
        ranks[i] = ranks[i - 1];
      else
        ranks[i] = i + 1;

      printf("%4d %4d", ranks[i], ts[i]);
      if (solved_count[ts[i]])
        printf(" %4d       %4d\n", solved_count[ts[i]], score[ts[i]]);
      else
        printf("\n");
    }
    if (t) printf("\n");
  }
}

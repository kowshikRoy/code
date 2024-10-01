/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-20
 * Task: 207
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canFinish(int n, vector<vector<int>>& pr) {
        vector<int> indegree(n);
        vector<vector<int>> g(n);
        for (auto v : pr) {
            int to = v[0], from = v[1];
            indegree[to]++;
            g[from].push_back(to);
        }

        int canTake = 0;
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0) {
                q.push(i);
                canTake++;
            }

        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            for (auto nxt : g[x]) {
                indegree[nxt]--;
                if (indegree[nxt] == 0) {
                    q.push(nxt);
                    canTake++;
                }
            }
        }
        return canTake == n;
    }
};

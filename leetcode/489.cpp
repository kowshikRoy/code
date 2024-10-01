/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-30
 * Task: 489
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the
 * cell.
 *     // Returns false if the cell in front is blocked and robot stays in the
 * current cell. bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
   private:
    set<array<int, 2>> s;
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

   public:
    void cleanRoom(Robot& r) { dfs(0, 0, 0, r); }
    void back(Robot& r) {
        r.turnRight();
        r.turnRight();
        r.move();
        r.turnRight();
        r.turnRight();
    }

    void dfs(int x, int y, int d, Robot& r) {
        if (s.count({x, y})) return;
        s.insert({x, y});
        r.clean();

        for (int i = 0; i < 4; i++) {
            int nd = (d + i) % 4;
            int xp = x + dir[nd][0], yp = y + dir[nd][1];
            if (s.find({xp, yp}) == s.end() && r.move()) {
                dfs(xp, yp, nd, r);
                back(r);
            }
            r.turnRight();
        }
    }
};

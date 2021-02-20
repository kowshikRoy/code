#include <bits/stdc++.h>
using namespace std;

int sx[3], sy[3];
int dx[3], dy[3];
int n;
char grid[10][10];
int dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    Point operator+(const Point &rhs) {
        Point res;
        res.x = x + rhs.x;
        res.y = y + rhs.y;
        if (res.x < 0 || res.x >= n || res.y < 0 || res.y >= n ||
            grid[res.x][res.y] == '#')
            return *this;
        return res;
    }

    bool operator==(const Point &rhs) const { return x == rhs.x && y == rhs.y; }

    bool operator<(const Point &rhs) const {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
};

struct Pos {
    Point A, B, C;
    Pos() {}
    Pos(Point A, Point B, Point C) : A(A), B(B), C(C) {}

    Pos move(Point d) {
        Pos nxt;
        nxt.A = A + d;
        nxt.B = B + d;
        nxt.C = C + d;
        return nxt;
    }

    bool operator<(const Pos &rhs) const {
        return A < rhs.A || (A == rhs.A && B < rhs.B) ||
               (A == rhs.A && B == rhs.B && C < rhs.C);
    }

    bool reached() {
        vector<Point> vec = {A, B, C};
        sort(vec.begin(), vec.end());
        if (vec[0] == Point(dx[0], dy[0]) && vec[1] == Point(dx[1], dy[1]) &&
            vec[2] == Point(dx[2], dy[2]))
            return true;
        return false;
        return true;
    }

    void print() {
        printf("A = (%d, %d)\n", A.x, A.y);
        printf("B = (%d, %d)\n", B.x, B.y);
        printf("C = (%d, %d)\n", C.x, C.y);
    }
};

int main() {
    int t, cs;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> grid[i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'A') sx[0] = i, sy[0] = j;
                if (grid[i][j] == 'B') sx[1] = i, sy[1] = j;
                if (grid[i][j] == 'C') sx[2] = i, sy[2] = j;
                if (grid[i][j] == 'X') dx[0] = i, dy[0] = j;
                if (grid[i][j] == 'Y') dx[1] = i, dy[1] = j;
                if (grid[i][j] == 'Z') dx[2] = i, dy[2] = j;
            }
        }
        Pos begin =
            Pos(Point(sx[0], sy[0]), Point(sx[1], sy[1]), Point(sx[2], sy[2]));
        queue<Pos> q;
        q.push(begin);
        map<Pos, int> Dis;
        Dis[begin] = 0;
        bool flag  = 0;
        while (!q.empty()) {
            Pos cur = q.front();
            q.pop();
            cur.print();
            if (cur.reached()) {
                flag = 1;
                cout << Dis[cur] << endl;
                break;
            }

            for (int i = 0; i < 4; i++) {
                Point d = Point(dir[i][0], dir[i][1]);
                Pos nxt = cur.move(d);
                if (Dis.count(nxt) == 0) {
                    q.push(nxt);
                    Dis[nxt] = 1 + Dis[cur];
                }
            }
        }
        if (!flag) cout << "trapped" << endl;
    }
}

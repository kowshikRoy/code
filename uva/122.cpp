/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-17
 * Task: 122
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

struct Node {
  Node *left, *right;
  bool isSet;
  int val;
  Node() {
    left = right = nullptr;
    isSet = false;
    val = 0;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  Node *root = nullptr;

  map<int, vector<int>> l;

  function<bool(Node *, int)> dfs = [&](Node *root, int lev) -> bool {
    if (root == nullptr) return true;
    if (!root->isSet) return false;
    l[lev].push_back(root->val);
    if (root->left) {
      if (!dfs(root->left, lev + 1)) return false;
    }
    if (root->right)
      if (!dfs(root->right, lev + 1)) return false;
    return true;
  };

  bool isComplete = true;
  while (cin >> s) {
    if (s == "()") {
      isComplete &= dfs(root, 0);
      if (isComplete == 0) {
        cout << "not complete" << endl;
      } else {
        int f = false;
        for (auto x : l) {
          for (auto y : x.second) {
            if (f) cout << " ";
            f = 1;
            cout << y;
          }
        }
        cout << endl;
      }
      l.clear();
      root = nullptr;
      isComplete = true;
      continue;
    }
    string temp = s.substr(1, s.size() - 2);
    if (root == nullptr) { root = new Node(); }

    auto k = temp.find(",");
    int num = stoi(temp.substr(0, k));
    string path = temp.substr(k + 1);
    auto cur = root;
    for (auto c : path) {
      if (c == 'L') {
        if (cur->left == nullptr) { cur->left = new Node(); }
        cur = cur->left;
      } else if (c == 'R') {
        if (cur->right == nullptr) { cur->right = new Node(); }
        cur = cur->right;
      }
    }
    if (cur->isSet) { isComplete = false; }
    cur->isSet = true;
    cur->val = num;
  }
  return 0;
}

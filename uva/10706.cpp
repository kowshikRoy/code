/**
 * Author: Repon Kumar Roy
 * Date: 2023-02-08
 * Task: 10706
 */

#include <algorithm>
#include <cassert>
#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

def find_digit(i):
    n = 1
    while True:
        k = n * (n + 1) // 2
        if i <= k:
            break
        i -= k
        n += 1
    i -= 1
    return (n + (i // n)) % 10

void solve() {
    
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}

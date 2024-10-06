/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-11
 * Task: 23
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *dummy = new ListNode(0);
    auto cmp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);
    for (auto L : lists) {
      if (L != nullptr) {
        pq.push(L);
      }
    }
    auto pre = dummy;
    while (!pq.empty()) {
      ListNode *x = pq.top();
      pq.pop();
      pre->next = x;
      if (x->next) {
        pq.push(x->next);
      }
      x->next = nullptr;
      pre = x;
    }
    return dummy->next;
  }
};

int main() { return 0; }

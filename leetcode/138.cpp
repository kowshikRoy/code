/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-11
 * Task: 138
 */

#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    auto cur = head;
    Node* dummy = new Node(0);
    Node* pre = dummy;
    unordered_map<Node*, Node*> H;
    while (cur) {
      Node* p = new Node(cur->val);
      pre->next = p;
      pre = p;
      H[cur] = p;
      cur = cur->next;
    }

    cur = head;
    auto cur2 = dummy->next;
    while (cur) {
      auto x = cur->random;
      if (H.count(x)) {
        cur2->random = H[x];
      }
      cur = cur->next;
      cur2 = cur2->next;
    }
    return dummy->next;
  }
};

int main() { return 0; }

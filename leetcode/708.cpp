/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-10
 * Task: 708
 */

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  Node* next;

  Node() {}

  Node(int _val) {
    val = _val;
    next = NULL;
  }

  Node(int _val, Node* _next) {
    val = _val;
    next = _next;
  }
};

class Solution {
 public:
  Node* insert(Node* head, int insertVal) {
    auto p = new Node(insertVal);
    p->next = p;
    if (head == nullptr) return p;
    auto prev = head, cur = head->next;
    do {
      if (prev->val <= cur->val) {
        if (insertVal >= prev->val && insertVal <= cur->val) {
          p->next = cur;
          prev->next = p;
          return head;
        }
      } else {
        if (insertVal >= prev->val || insertVal <= cur->val) {
          p->next = cur;
          prev->next = p;
          return head;
        }
      }
      prev = cur;
      cur = cur->next;
    } while (prev != head);
    prev->next = p;
    p->next = cur;

    return head;
  }
};

int main() { return 0; }

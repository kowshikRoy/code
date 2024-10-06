/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-27
 * Task: 328
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    ListNode *even = new ListNode(0), *odd = new ListNode(0);
    auto p1 = even, p2 = odd, cur = head;
    for (int i = 1; cur; i++) {
      auto nxt = cur->next;
      cur->next = nullptr;
      if (i & 1)
        p2->next = cur, p2 = cur;
      else
        p1->next = cur, p1 = cur;
      cur = nxt;
    }
    if (p2 == odd) return even->next;
    p2->next = even->next;
    return odd->next;
  }
};

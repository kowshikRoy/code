/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-11
 * Task: 21
 */

#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        auto pre        = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                pre->next = l1;
                pre       = l1;
                l1        = l1->next;
            } else {
                pre->next = l2;
                pre       = l2;
                l2        = l2->next;
            }
        }
        while (l1) pre->next = l1, pre = l1, l1 = l1->next;
        while (l2) pre->next = l2, pre = l2, l2 = l2->next;
        return dummy->next;
    }
};

int main() { return 0; }

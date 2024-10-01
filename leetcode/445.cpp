/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-11
 * Task: 445
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto p1 = reverseList(l1), p2 = reverseList(l2);
        int carry     = 0;
        ListNode *pre = nullptr;
        while (p1 || p2) {
            int sum = (p1 ? p1->val : 0) + (p2 ? p2->val : 0) + carry;
            carry   = sum / 10;
            sum %= 10;
            auto now  = new ListNode(sum);
            now->next = pre;
            pre       = now;
            if(p1) p1 = p1->next;
            if(p2) p2 = p2->next;
        }
        if (carry) {
            auto now  = new ListNode(1);
            now->next = pre;
            return now;
        }
        return pre;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *pre = nullptr, *cur = head;
        while (cur) {
            auto tmp  = cur->next;
            cur->next = pre;
            pre       = cur;
            cur       = tmp;
        }
        return pre;
    }
};

int main() { return 0; }

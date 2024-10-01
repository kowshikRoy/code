/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-11
 * Task: 234-a
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
    bool isPalindrome(ListNode *head) {
        if (head == nullptr) return true;
        auto slow = head, fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto p   = reverseList(slow->next);
        auto cur = head;
        while (p) {
            if (cur->val != p->val) return false;
            cur = cur->next;
            p   = p->next;
        }
        return true;
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

/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-11
 * Task: 206
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        auto cur      = head;
        ListNode* pre = nullptr;
        while (cur) {
            auto p    = cur->next;
            cur->next = pre;
            pre       = cur;
            cur       = p;
        }
        return pre;
    }
};

int main() { return 0; }

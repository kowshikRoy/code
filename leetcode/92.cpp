/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-11
 * Task: 92
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto cur       = head;
        ListNode* last = nullptr;
        for (int i = 0; i < left - 1; i++) {
            last = cur;
            cur  = cur->next;
        }

        auto beforeBegin = last;
        auto begin      = cur;
        cur             = head;

        last = nullptr;
        for (int i = 0; i < right; i++) {
            last = cur;
            cur  = cur->next;
        }
        auto end      = last;
        auto afterEnd = cur;

        last = nullptr;
        cur  = begin;
        while (cur != end) {
            auto tmp  = cur->next;
            cur->next = last;
            last      = cur;
            cur       = tmp;
        }
        beforeBegin->next = last;
        begin->next       = afterEnd;
        return head;
    }
};

int main() { return 0; }

/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-11
 * Task: 1836
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
    ListNode *deleteDuplicatesUnsorted(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur   = head;
        unordered_map<int, int> cnt;
        while (cur) cnt[cur->val]++, cur = cur->next;
        ListNode *pre = dummy;
        cur           = head;
        while (cur) {
            if (cnt[cur->val] == 1) {
                pre->next = cur;
                pre       = cur;
            }
            cur       = cur->next;
            pre->next = nullptr;
        }
        return dummy->next;
    }
};

int main() { return 0; }

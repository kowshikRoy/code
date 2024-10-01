/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-10
 * Task: 1474
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
    ListNode *deleteNodes(ListNode *head, int m, int n) {
        if (n == 0 || head == nullptr) return nullptr;
        auto cur  = head;
        auto last = head;
        while (cur) {
            for (int i = 0; i < m && cur; i++) last = cur, cur = cur->next;
            for (int i = 0; i < n && cur; i++) cur = cur->next;
            last->next = cur;
        }
        return head;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    ListNode *head = nullptr, *pre = nullptr;
    for (auto x : nums) {
        auto ptr = new ListNode(x);
        if (head == nullptr) {
            head = ptr;
        } else {
            pre->next = ptr;
        }
        pre = ptr;
    }
    auto t = Solution().deleteNodes(head, 2, 3);
    while (t) {
        cout << t->val << endl;
        t = t->next;
    }

    return 0;
}

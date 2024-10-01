/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-11
 * Task: 234
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
        string s;
        auto cur = head;
        while (cur) s.push_back(cur->val), cur = cur->next;
        for (int i = 0, j = (int)s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
};

int main() { return 0; }

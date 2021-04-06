#include "util.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        if (l1->val > l2->val) {
            helper(l1, l2->next, l2);
            return l2;
        }
        else {
            helper(l1->next, l2, l1);
            return l1;
        }
    }

    void helper(ListNode* l1, ListNode* l2, ListNode* cur) {
        if (l1 == nullptr)
            cur->next = l2;
        else if (l2 == nullptr)
            cur->next = l1;
        else if (l1->val < l2->val) {
            cur->next = l1;
            helper(l1->next, l2, cur->next);
        }
        else {
            cur->next = l2;
            helper(l1, l2->next, cur->next);
        }
    }

};

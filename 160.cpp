#include "util.h"

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        auto lenA = size(headA);
        auto lenB = size(headB);

        while(lenA > lenB) {
            headA = headA->next;
            --lenA;
        }

        while(lenB > lenA) {
            headB = headB->next;
            --lenB;
        }

        while(headA != nullptr) {
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }

private:
    int size(ListNode* head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }
};

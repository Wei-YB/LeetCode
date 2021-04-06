#include "util.h"

class Solution {
    pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail){
        if(head == tail)
            return {head, tail};
        reverse(head->next, tail);
        head->next->next = head;
        head->next = nullptr;
        return {tail, head};
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto* cur = head;
        int cnt = 0;
        while(cur){
            ++cnt;
            if(cnt == k){
                auto* ret = reverseKGroup(cur->next, k);
                auto [newHead, tail] = reverse(head, cur);
                tail->next = ret;
                return newHead;
            }
            cur = cur->next;
        }
        return head;
    }
};
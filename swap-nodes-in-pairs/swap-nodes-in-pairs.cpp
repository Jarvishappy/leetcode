#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (NULL == head) {
            return head;
        }

        ListNode *m = head, *n = m->next, *pre_m = NULL, *next_n = NULL;

        ListNode *newHead;
        // length >= 2
        if (n != NULL) {
            newHead = n;
        } else {
            newHead = head;
        }

        while (n != NULL) {
            next_n = n->next;
            n->next = m;
            m->next = next_n;
            if (pre_m != NULL) {
                pre_m->next = n;
            }

            pre_m = m;
            m = next_n;

            n = m == NULL ? NULL : m->next;
        }

        return newHead;
    }
};



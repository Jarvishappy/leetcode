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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (NULL == head || m == n)
            return head;

        // 1 <= m <= n
        int diff = n - m;
        // find mth node first
        ListNode *pm = head, *pre_m = NULL;
        while (m-- > 1) {
            pre_m = pm;
            pm = pm->next;
        }

        // find nth node
        ListNode *pn = pm, *next_pn = NULL;
        while (diff--) {
            pn = pn->next;
        }

        // pn不会等于NULL
        next_pn = pn->next;

        // 到达pn->next之后开始回溯
        reverseBetween(NULL, pm, next_pn);

        ListNode *revHead = NULL;
        // m > 1
        if (pre_m != NULL) {
            pre_m->next = pn;
            revHead = head;
        }
        else {  // m == 1
            revHead = pn;
        }
        pm->next = next_pn;

        return revHead;
    }

    void reverseBetween(ListNode *pre, ListNode *cur, ListNode *stop) {
        if (cur == stop) {
            return;
        }
        reverseBetween(cur, cur->next, stop);
        cur->next = pre;
    }
};



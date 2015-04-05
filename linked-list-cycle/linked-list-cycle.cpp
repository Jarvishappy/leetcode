#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * 思路：
     * 用2个指针，p和q，q的速度比p快，如果最终p和q相遇了，表示有环，
     * 一旦有环，那么p和q最终都会陷入那个环中。
     *
     */
    bool hasCycle(ListNode *head) {
        ListNode *p = head, *q = head;
        // Vq = 2Vp
        while (q != NULL) {
            p = p->next;
            if (q->next != NULL) {
                q = q->next->next;
            } else {
                q = NULL;
            }

            if (p != NULL && q != NULL && p == q) {
                return true;
            }
        }

        return false;
    }
};


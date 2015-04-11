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
    /**
     * 思路：
     * 用2个指针，一起向尾部移动，如果val相等，那么就remove在前面的指针指向的节点。
     * 指针一起移动的前提：
     * 2个指针指向的节点val不同
     *
     */
    ListNode *deleteDuplicates(ListNode *head) {
        if (NULL == head)
            return head;
        ListNode *p = head, *q = p->next;
        ListNode *tmp = NULL;

        while (q != NULL) {
            if (p->val == q->val) {
                tmp = q->next;
                p->next = q->next;
                q->next = NULL;
                // reclaim memory
                delete q;
                q = tmp;
            } else {
                p = q;
                q = q->next;
            }
        }

        return head;
    }
};


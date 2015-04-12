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
     * 要移除所有的有重复的元素，用2个指针，指针之间的范围里是重复的元素，
     * 然后移除这个区间内的节点，要用delete释放内存，而不是仅仅改变指针就行了
     *
     */
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) {
            return head;
        }

        ListNode *m = head, *n = m->next,
                 *pre_m = NULL,
                 *next_n = nextN(n);
        ListNode *newHead = head;

        while (n != NULL) {
            if (m->val == n->val) {
                if (n->next != NULL && m->val == n->next->val) {
                    n = n->next;
                    next_n = nextN(n);
                } else {
                    // m > 1 (1表示头节点）
                    if (pre_m != NULL) {
                        freeList(m, next_n);
                        pre_m->next = next_n;
                        m = next_n;
                        n = nextM(m);
                        next_n = nextN(n);

                    } else {    // m == 1
                        freeList(m, next_n);
                        m = next_n;
                        n = nextM(m);
                        next_n = nextN(n);
                        newHead = m;
                    }
                }
            } else {
                pre_m = m;
                m = m->next;
                n = nextM(m);
                next_n = nextN(n);

            }
        }

        return newHead;
    }

    /**
     * 释放掉[m,n)区间节点的内存
     */
    void freeList(ListNode *m, ListNode const *n) {
        if (m == n)
            return;

        freeList(m->next, n);
        m->next = NULL;
        delete m;
        m = NULL;
    }

    ListNode* nextM(ListNode *m) {
        return m == NULL ? NULL : m->next;
    }

    ListNode* nextN(ListNode *n) {
        return n == NULL ? NULL : n->next;
    }
};



#include <stdio.h>
#include <stdlib.h>




struct ListNode {
    int val;
    struct ListNode *next;
};


/**
 * 2个链表可能长度不一样，我们需要先计数2个链表的长度，然后
 * 从长度一样的地方开始逐个比较2个链表的节点，找到相交的节点
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
        if (NULL == headA || NULL == headB)
                return NULL;
        struct ListNode *p, *q;
        struct ListNode *tailA, *tailB;
        int lenA = 0, lenB = 0;
        for (p = headA, q = headB; ; ) {
                if (p != NULL) {
                        lenA++;
                        if (p->next == NULL)
                                tailA = p;
                        p = p->next;
                }
                if (q != NULL) {
                        lenB++;
                        if (q->next == NULL)
                                tailB = q;
                        q = q->next;
                }
                if (!p && !q)
                        break;
        }

        /* 最后个节点不相等，那么一定不相交 */
        if (tailA != tailB)
                return NULL;

        p = headA;
        q = headB;
        while (lenA > lenB) {
                p = p->next;
                lenA--;
        }
        while (lenB > lenA) {
                q = q->next;
                lenB--;
        }

        /* 此时链表A, B长度相等，逐个比较每个节点 */
        while (p != NULL) {
                if (p == q)
                        return p;

                p = p->next;
                q = q->next;
        }

        return NULL;
}




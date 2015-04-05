#include <iostream>
using namespace std;

/*
 * Definition for singly-linked list.
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
     * 向右旋转链表。先找到新的头，即倒数第k个元素，然后用p指向旧头，
     * q指向新头，有很多边界条件要处理
     *
     */
    ListNode *rotateRight(ListNode *head, int k) {
        if (NULL == head || k == 0) {
            return head;
        }

        ListNode *p = head, *q = head, *v = head;
        // 找到新的链表头
        int n = k;
        int len = 0;
        while (v != NULL && n--) {
            v = v->next;
            len++;
        }

        // k == len则无需反转，k > len需要重新计算v
        if (v == NULL && n >= 0) {
            n = k % len;
            if (n == 0)
                return head;

            v = head;
            while (n--) {
                v = v->next;
            }
        }


        // 将q指向new head，v指向最末尾元素
        while (v != NULL) {
            if (v->next == NULL) {
                q = q->next;
                break;
            }
            q = q->next;
            v = v->next;
        }

        ListNode *newHead = q;

        // 把末尾元素接到old head
        v->next = head;

        // 把q之前的元素的next指向NULL
        while (p->next != q) {
            p = p->next;
        }
        p->next = NULL;

        return newHead;
    }
};



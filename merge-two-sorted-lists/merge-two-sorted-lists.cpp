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
     * 妈蛋！这道题费了我这么多时间，一直WA的原因：
     * 一开始的思路太狭隘了，认为只要逐一进行比较，把小的元素连接到大的元素前面就可以了。
     * 后来发现这种思路是不对的! 合并的时候只能把一个链表，往另外一个链表上合，而不能
     * 一会把l1连接到l2，一会又把l2连接到l1。还有用到前驱指针的时候，一定要注意在哪些情况
     * 下要修改前驱指针的状态，也就说，这种链表的题目，一般你会用到多个指针，你需要想清楚
     * 这些指针在什么情况下要修改他们的状态，这是最容易出错的地方了，从来没有一次没被坑过。
     *
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;


        ListNode *p = l1, *q = l2, *tmp, *pre_q = NULL;
        while (p != NULL && q != NULL) {
            if (q->val < p->val) {
                pre_q = q;
                q = q->next;
            } else {
                tmp = p->next;
                p->next = q;
                if (NULL != pre_q) {
                    pre_q->next = p;
                }
                pre_q = p;
                p = tmp;
            }
        }

        if (q == NULL && p != NULL) {
            pre_q->next = p;
        }

        return l1->val <= l2->val ? l1 : l2;
    }

};


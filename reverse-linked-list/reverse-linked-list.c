#include <stdio.h>
#include <stdlib.h>

 struct ListNode {
     int val;
     struct ListNode *next;
 };

void recursive_reverse(struct ListNode* pre, struct ListNode* cur, struct ListNode** head);

/**
 * Algorithm:
 * 递归到最后一个节点，然后回溯
 */
struct ListNode* reverseList(struct ListNode* head) {
        if (NULL == head)
                return head;

        recursive_reverse(NULL, head, &head);
        return head;
}


void recursive_reverse(struct ListNode* pre, struct ListNode* cur, struct ListNode** head)
{
        if (cur == NULL) {
                *head = pre;
                return;
        }

        recursive_reverse(cur, cur->next, head);
        cur->next = pre;
}


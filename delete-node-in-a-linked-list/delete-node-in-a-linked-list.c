#include <stdio.h>
#include <stdlib.h>


/**
 * Algorithm:
 * 把下一个节点的值赋值到当前节点的值，然后再把next指针置为node->next->next
 */
void deleteNode(struct ListNode* node) {
        if (node == NULL || node->next == NULL)
                return;

        node->val = node->next->val;
        node->next = node->next->next;
}



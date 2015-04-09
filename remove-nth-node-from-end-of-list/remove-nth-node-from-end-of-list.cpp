#include <iostream>
using namespace std;
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
     * 移除倒数第n个节点，并返回头节点
     *
     *
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (NULL == head) {
            return head;
        }

        ListNode *fast = head, *slow = head, *pre_slow = NULL;
        while (fast != NULL && n--) {
            fast = fast->next;
        }

        // n == length, remove head
        if (fast == NULL) {
            head = head->next;
            return head;
        }

        // n > length 这种情况应该不存在
        // n < length, new head is same as old head
        while (fast != NULL) {
            fast = fast->next;
            pre_slow = slow;
            slow = slow->next;
        }

        // remove slow
        pre_slow->next = slow->next;
        slow->next = NULL;

        return head;
    }


};

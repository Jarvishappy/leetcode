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
     * 三个指针：haed, last_sorted, first_unsorted
     */
    ListNode *insertionSortList(ListNode* head) {
        if (NULL == head)
            return head;

        ListNode *lst_so = head, *f_unso = lst_so->next;

        while (f_unso != NULL) {
            findPosAndInsert(head, lst_so, f_unso);
            f_unso = lst_so->next;
        }

        return head;
    }

    /**
     * find the position between [head, last_sorted] to insert node p.
     * @return new head
     */
    void findPosAndInsert(ListNode *&head, ListNode *&last_sorted, ListNode *n) {
        ListNode *pos = head;
        ListNode *pre_pos = NULL;
        ListNode *next_n = NULL;

        while (pos != last_sorted->next) {
            if (n->val > pos->val) {
                pre_pos = pos;
                pos = pos->next;
            } else {
                // insert n before pos
                if (NULL != pre_pos) {
                    pre_pos->next = n;
                }
                next_n = n->next;
                n->next = pos;
                // update last_sorted->next
                last_sorted->next = next_n;

                // update head
                if (pos == head) {
                    head = n;
                }
                return;
            }
        }

        // n > last_sorted, update last_sorted
        last_sorted = n;
    }

};



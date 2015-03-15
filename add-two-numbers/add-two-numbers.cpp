#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (l1 == NULL && l2 == NULL)
            return NULL;


        ListNode *p = l1, *q = l2;
        // pointers for result list
        ListNode *s = NULL;
        // head of result list
        ListNode *h = NULL;
        int carry = 0;
        int sum = 0;

        while (p != NULL || q != NULL)
        {

            if (p != NULL && q != NULL)
            {
                sum = p->val + q->val + carry;
                p=p->next;
                q=q->next;
            }
            else if (p == NULL && q != NULL)
            {
                sum = q->val + carry;
                q=q->next;
            }
            else if (q == NULL && p != NULL)
            {
                sum = p->val + carry;
                p=p->next;
            }


            carry = sum / 10;
            sum = sum % 10;

            ListNode *sumNode = new ListNode(sum);
            // remember head node
            if (h == NULL) {
                h = sumNode;
                s = h;
            }
            else
            {
                s->next = sumNode;
                s = sumNode;
            }
        }

        if (0 != carry)
        {
            ListNode *node = new ListNode(carry);
            s->next = node;
            s = node;
        }


        return h;
    }
};


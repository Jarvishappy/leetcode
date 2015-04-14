#include <iostream>
#include <set>

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
     * 思路：
     * 用一个set装遍历过的节点
     *
     */
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
            return NULL;

        set<ListNode*> visited;
        ListNode *p = head;
        while (p != NULL) {
            if (visited.count(p) != 0) {
                return p;
            } else {
                visited.insert(p);
                p = p->next;
            }
        }

        return NULL;
    }
};



#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
void divide(Node *head, int len, Node **left, Node **right);
Node *merge(Node *left, Node *right);
struct ListNode *mergeSort(Node *head, int plen);
int lengthOf(Node *head);

/**
 * 归并排序算法
 */
struct ListNode* sortList(Node* head) {
        if (head == NULL)
                return NULL;
        int len = lengthOf(head);
        head = mergeSort(head, len);
        return head;
}

struct ListNode *mergeSort(Node *head, int len)
{
        if (len == 1)
                return head;
        Node *left, *right;
        divide(head, len, &left, &right);
        int halfLen = len / 2;
        left = mergeSort(left, halfLen);
        right = mergeSort(right, len - halfLen);
        return merge(left, right);
}

int lengthOf(Node *head)
{
        int len = 0;
        while (head != NULL) {
                len++;
                head = head->next;
        }

        return len;
}

/**
 * 链表的长度只需要计算一次，后续的递归调用只要把len = len / 2就可以了
 */
void divide(Node *head, int len, Node **left, Node **right)
{
        int length = len / 2;
        Node *p, *q;
        *left = p = head;
        for (int i = 0; i < length; ++i) {
                q = p;
                p = p->next;
        }
        q->next = NULL;
        *right = p;
}

/**
 * 把链表right合并到left上，合并后的链表元素是按升序排列的
 *
 */
Node *merge(Node *left, Node *right)
{
        Node *p = left, *pprev = NULL,
             *q = right, *qstart = NULL,
             *qnext, *head;

        head = (q->val < p->val) ? q : p;

        while (q != NULL) {
                if (q->val < p->val) {
                        /* q比p小，q继续向前，直到q->next > p */
                        qstart = q; /* 记录q的起始位置 */
                        while (q->next != NULL && (q->next->val < p->val))
                                q = q->next;

                        /* q插入到p的前面 */
                        qnext = q->next;
                        q->next = p;
                        if (pprev != NULL) {
                                pprev->next = qstart;
                        }
                        q = qnext;
                } else {
                        /* q比p大，p向前移动一步 */
                        if (p->next != NULL) {
                                pprev = p;
                                p = p->next;
                        } else {
                                /* p已经是最后一个节点了，把剩余的q直接接到p的后面 */
                                p->next = q;
                                break;
                        }
                }
        }

        return head;
}


void printList(Node *head)
{
        char buf[256] = {0};
        while (head) {
                sprintf(buf, "%s%d ", buf, head->val);
                head = head->next;
        }

        printf("%s\n", buf);
}

/**
 * 用数组arr创建一个链表
 */
Node *createList(int *arr, int count)
{
        Node *n, *head, *pre;

        /* create head first */
        n = malloc(sizeof(*n));
        n->val = arr[0];
        head = n;
        pre = head;

        for (int i = 1; i < count; ++i) {
                n = malloc(sizeof(*n));
                n->val = arr[i];
                n->next = NULL;

                pre->next = n;
                pre = n;
        }

        return head;
}



int main(int argc, char *argv[])
{
        /* int a[] = {20, 38, 55};
         * int b[] = {10, 15, 30, 35, 44, 50, 60, 70}; */
        int c[] = {8, 3, 7, 1, 6, 2, 5, 4};

        Node *listC = createList(c, 8);
        Node *sorted = sortList(listC);

        printList(sorted);

/*         Node *listA = createList(a, 3);
 *         Node *listB = createList(b, 8);
 * 
 *         Node *mergedList = merge(listA, listB);
 * 
 *         printList(mergedList); */

        printf("done!\n");

        return 0;
}




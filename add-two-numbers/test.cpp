#include "add-two-numbers.cpp"

/**
 * Create linked list from tear
 *
 */
ListNode* createList(int a[], const int size)
{
    ListNode *head = NULL;
    for (int i = 0; i < size; ++i)
    {
        ListNode *newNode = new ListNode(a[i]);
        newNode->next = head;
        head = newNode;
    }

    return head;
}

ListNode* createListFromHead(int a[], const int size)
{
    ListNode *head = NULL;
    ListNode *p = NULL;
    for (int i = 0; i < size; ++i)
    {
        ListNode *newNode = new ListNode(a[i]);
        if (i == 0)
        {
            head = newNode;
            p = head;
        }
        else
        {
            p->next = newNode;
            p = newNode;
        }
    }


    return head;
}

void printList(ListNode *head)
{
    cout << "List: [";
    for (ListNode *p = head; p != NULL; p = p->next)
    {
        cout << p->val;
        if (p->next != NULL)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}


int main(int argc, char *argv[])
{
    int a[] = {5};
    int b[] = {5};
    ListNode* l1 = createListFromHead(a, 1);
    ListNode* l2 = createListFromHead(b, 1);

    printList(l1);
    printList(l2); 

    Solution s;
    ListNode *ret = s.addTwoNumbers(l1, l2);
    printList(ret);

    cout << "done!" << endl;

    return 0;
}

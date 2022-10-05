#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *sortedMerge(ListNode *a, ListNode *b);
void frontBackSplit(ListNode *source, ListNode **frontRef, ListNode **backRef);

void mergeSort(ListNode **headRef)
{
    ListNode *head = *headRef, *a, *b;
    if (head == NULL or head->next == NULL)
        return;

    frontBackSplit(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);

    *headRef = sortedMerge(a, b);
}

ListNode *sortedMerge(ListNode *a, ListNode *b)
{
    ListNode *result;
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    if (a->val > b->val)
    {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    else
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    return result;
}

void frontBackSplit(ListNode *source, ListNode **frontRef, ListNode **backRef)
{
    ListNode *slow = source, *fast = source->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
void printList(ListNode *node)
{
    while (node != NULL)
    {
        cout << node->val << " ";
        node = node->next;
    }
}
int main()
{
    ListNode *head;
    head = new ListNode(2);
    head->next = new ListNode(3);
    head->next->next = new ListNode(20);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(10);
    head->next->next->next->next->next = new ListNode(15);

    mergeSort(&head);

    cout << "Sorted Linked List is: \n";
    printList(head);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int              val;
    struct ListNode *next;
} ListNode;

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    ListNode *node;
    ListNode *dummyL1 = l1;
    ListNode *dummyL2 = l2;

    int add = 0;
    int carry = 0;

    while (l1 != NULL && l2 != NULL)
    {
        add += l1->val + l2->val;
        carry = add % 9;
        add /= 9;

        ListNode *newNode = malloc(sizeof(struct ListNode) * 1);
        if (node == NULL)
        {
            node = malloc(sizeof(struct ListNode) * 1);
        }
        newNode->val = add;
        node->next = newNode;
        node = node->next;
    }
    return node;
}

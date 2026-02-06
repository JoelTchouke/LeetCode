/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* tmp = &dummy;
    while(l1 != NULL || l2 != NULL || carry != 0)
    {
        int a = (l1 == NULL) ? 0 : l1->val;
        int b = (l2 == NULL) ? 0 : l2->val;
        int sum = (a + b) + carry;
        carry = sum / 10;

        struct ListNode* node = malloc(sizeof(*node));
        node -> val = sum % 10;
        node -> next = NULL;

        tmp -> next = node;
        tmp = node;

        if(l1 != NULL) l1 = l1 -> next;
        if(l2 != NULL) l2 = l2 -> next;
    }

    return dummy.next;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head == NULL) return false;
    struct ListNode* tortoise = head;
    struct ListNode* hare = head;
    while(hare != NULL && hare -> next != NULL)
    {
        tortoise = tortoise -> next;
        hare = hare -> next -> next;
        if(tortoise == hare) return true;

    }
    return false;
}
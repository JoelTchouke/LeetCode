/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head == NULL) return NULL;
    struct ListNode* currentNode = head;
    while( head !=NULL && head -> val == val)
    {
        head = head -> next;
        currentNode = head;
    }
    while(currentNode != NULL && currentNode -> next != NULL)
    {
        if(currentNode->next->val == val)
        {
            currentNode->next = currentNode->next->next;
        }
        else
        {
            currentNode = currentNode -> next;
        }

    }
    return head;
}
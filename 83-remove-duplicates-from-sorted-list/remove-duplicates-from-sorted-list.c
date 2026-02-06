/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* currentNode = head;
    while(currentNode != NULL && currentNode -> next != NULL)
    {
        int currentVal = currentNode -> val;
        int nextVal = currentNode -> next -> val;
        if(currentVal == nextVal)
        {
            currentNode -> next = currentNode -> next -> next;
        }
        else
        {
            currentNode = currentNode -> next;
        }
    }

    return head;
    
}
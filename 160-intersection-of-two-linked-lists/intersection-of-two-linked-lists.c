/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* currentNode = headB;
    while(headA != NULL)
    {
        while(currentNode != NULL)
        {
            if(currentNode == headA) return currentNode;
            currentNode = currentNode -> next;            
        }
        currentNode = headB;
        headA = headA->next;
    }

    return NULL;
}
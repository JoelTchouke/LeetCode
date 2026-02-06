/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
   size_t listSize = 0;
   int pos;
   struct ListNode* currentNode = head;
   while(currentNode != NULL) 
   {
        listSize++;
        currentNode = currentNode->next;
   }
    pos = listSize;
    currentNode = head;
    while(head != NULL && n == pos)
    {
        head = head->next;
        currentNode = head;
        pos--;
    }

    while(currentNode != NULL && currentNode->next != NULL)
    {
        if(n == pos - 1)
        {
            currentNode->next = currentNode->next->next;
            return head;
        }
        else
        {
            pos--;
            currentNode = currentNode->next;
        }
    }

    return head;
}
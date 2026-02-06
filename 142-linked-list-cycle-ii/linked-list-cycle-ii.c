/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* turtoise = head;
    struct ListNode* hare     = head;
    bool cycleFound = false;
    while(hare != NULL && hare -> next != NULL && cycleFound == false)
    {
        turtoise = turtoise -> next;
        hare = hare -> next -> next;
        if(hare == turtoise) 
        {
            cycleFound = true;
        }
    }
    if(cycleFound)
    {
        turtoise = head;
        while(turtoise != hare)
        {
            turtoise = turtoise -> next;
            hare = hare -> next;
        }
        return hare;
    }

    return NULL;

}
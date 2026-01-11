/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        bool cycleEncountered = false;
        unordered_set <ListNode*> encounteredNodes;
        ListNode* currentNode = head;
        while (currentNode != NULL)
        {
            if(encounteredNodes.find(currentNode) != encounteredNodes.end())
            {
                cycleEncountered = true;
                break;
            }
            else
            {
                encounteredNodes.insert(currentNode);
                currentNode = currentNode -> next;
            }
        }
        return cycleEncountered;
        
    }
};
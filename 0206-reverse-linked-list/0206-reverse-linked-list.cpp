/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode *previousNode = nullptr;
        ListNode *nextNode = head -> next;
        while(nextNode)
        {
            head -> next = previousNode;
            previousNode = head;
            head = nextNode;
            nextNode = head -> next;
        }

        head -> next = previousNode;

        return head;

    }
};
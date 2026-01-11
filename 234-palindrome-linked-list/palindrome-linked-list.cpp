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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)
        {
            return true;
        }
        ListNode* currentNode = head;;
        string palindromeToTest = "";

        while(currentNode != nullptr)
        {
            palindromeToTest += (char) (currentNode -> val);
            currentNode = currentNode -> next;
        }
        string reversePalindromeToTest = palindromeToTest;
        reverse(reversePalindromeToTest.begin(), reversePalindromeToTest.end());
        return (palindromeToTest == reversePalindromeToTest);
    }
};
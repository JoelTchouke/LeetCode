/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    int i = 0;
    int start = 0;
    int finish;
    struct ListNode* currentNode = head;
    while(currentNode != NULL)
    {
        currentNode = currentNode->next;
        i++;
    }
    int arr[i];
    int sizeOfArr = i;
    i = 0;
    currentNode = head;
    while(currentNode != NULL)
    {
        arr[i] = currentNode -> val;
        currentNode = currentNode->next;
        i++;
    }
    finish = sizeOfArr - 1;
    for(int i = 0; i < sizeOfArr/2; i++)
    {
        if(arr[start + i] != arr[finish - i]) return false;
    }
    return true;
}
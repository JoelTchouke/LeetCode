#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int* nextLargerNodes(struct ListNode* head, int* returnSize) {
    // Count nodes
    int n = 0;
    struct ListNode* curr = head;
    while (curr) {
        n++;
        curr = curr->next;
    }

    *returnSize = n;
    if (n == 0) return NULL;

    int* result = (int*)malloc(n * sizeof(int));

    curr = head;
    for (int i = 0; i < n; i++) {
        struct ListNode* dummy = curr->next;

        // Look ahead for next greater node
        while (dummy && dummy->val <= curr->val) {
            dummy = dummy->next;
        }

        if (dummy) {
            result[i] = dummy->val;
        } else {
            result[i] = 0;
        }

        curr = curr->next;
    }

    return result;
}
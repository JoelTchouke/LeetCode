#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int* nextLargerNodes(struct ListNode* head, int* returnSize) {
    // First pass: count nodes
    int n = 0;
    struct ListNode* curr = head;
    while (curr) {
        n++;
        curr = curr->next;
    }

    *returnSize = n;
    if (n == 0) {
        return NULL;
    }

    // Store list values in an array
    int* values = (int*)malloc(n * sizeof(int));
    curr = head;
    for (int i = 0; i < n; i++) {
        values[i] = curr->val;
        curr = curr->next;
    }

    // Result array initialized to 0
    int* result = (int*)calloc(n, sizeof(int));

    // Stack of indices
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++) {
        while (top >= 0 && values[i] > values[stack[top]]) {
            result[stack[top]] = values[i];
            top--;
        }
        stack[++top] = i;
    }

    free(values);
    free(stack);

    return result;
}
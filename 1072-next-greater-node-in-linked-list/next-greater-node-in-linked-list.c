/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextLargerNodes(struct ListNode* head, int* returnSize) {
    // Count nodes and flatten to array for easy indexing
    int n = 0;
    struct ListNode* curr = head;
    while (curr) { n++; curr = curr->next; }

    *returnSize = n;
    if (n == 0) return NULL;

    int* vals   = (int*)malloc(n * sizeof(int));
    int* result = (int*)calloc(n, sizeof(int));  // calloc → 0-initialized
    int* stack  = (int*)malloc(n * sizeof(int));  // stores indices
    int  top    = -1;

    // Flatten list
    curr = head;
    for (int i = 0; i < n; i++, curr = curr->next)
        vals[i] = curr->val;

    for (int i = 0; i < n; i++) {
        // Current value beats everything smaller waiting on the stack
        while (top >= 0 && vals[stack[top]] < vals[i]) {
            result[stack[top]] = vals[i];  // found the answer for that index
            top--;
        }
        stack[++top] = i;  // push current index; its answer is unknown for now
    }

    free(vals);
    free(stack);
    return result;
}
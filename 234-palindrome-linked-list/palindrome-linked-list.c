

static struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    while (head != NULL) {
        struct ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return true;

    // 1) Find middle (slow)
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2) If odd length, skip the middle node
    if (fast != NULL) { // odd number of nodes
        slow = slow->next;
    }

    // 3) Reverse second half
    struct ListNode* second = reverseList(slow);

    // 4) Compare halves
    struct ListNode* p1 = head;
    struct ListNode* p2 = second;
    bool ok = true;

    while (p2 != NULL) {            // only need to walk the second half
        if (p1->val != p2->val) {
            ok = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    // 5) Optional: restore list
    reverseList(second);

    return ok;
}

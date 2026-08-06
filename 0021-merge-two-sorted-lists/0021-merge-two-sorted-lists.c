struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    struct ListNode * dummyStart = list1->val > list2->val ? list2 : list1;
    struct ListNode * head = dummyStart;
    struct ListNode * unselected = head == list1 ? list2 : list1;
    
    while(head->next)
    {
        if (head->next->val > unselected->val) {
            struct ListNode * temp = head->next;
            head->next = unselected;
            unselected = temp; 
        }
        head = head->next;
    }
    
    head->next = unselected;
    return dummyStart; 
}

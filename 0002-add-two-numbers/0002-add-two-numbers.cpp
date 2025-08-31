class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::vector<int> sumArr;
        int carry = 0;

        // Step 1: Perform the addition (reversed digits)
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;  // FIXED!
            }

            carry = sum / 10;
            sumArr.push_back(sum % 10);
        }

        // Step 2: Build the linked list in the correct order
        ListNode* head = nullptr;
        ListNode* currentNode = nullptr;

        for (int i = 0; i < sumArr.size(); i++) {
            ListNode* newNode = new ListNode(sumArr[i]);
            if (!head) {
                head = newNode;
                currentNode = head;
            } else {
                currentNode->next = newNode;
                currentNode = currentNode->next;
            }
        }

        return head;
    }
};

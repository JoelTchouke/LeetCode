class MyLinkedList {
private:
    ListNode* head;

public:
    MyLinkedList() : head(nullptr) {}

    int get(int index) {
        if (index < 0) return -1;
        ListNode* cur = head;
        for (int i = 0; cur != nullptr && i < index; i++) {
            cur = cur->next;
        }
        return (cur == nullptr) ? -1 : cur->val;
    }

    void addAtHead(int val) {
        head = new ListNode(val, head);
    }

    void addAtTail(int val) {
        ListNode* node = new ListNode(val, nullptr);

        if (head == nullptr) {
            head = node;
            return;
        }

        ListNode* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = node;
    }

    void addAtIndex(int index, int val) {
        if (index <= 0) {              // includes negative index behavior
            addAtHead(val);
            return;
        }

        ListNode* cur = head;
        for (int i = 0; cur != nullptr && i < index - 1; i++) {
            cur = cur->next;
        }

        if (cur == nullptr) return;    // index > length => do nothing

        cur->next = new ListNode(val, cur->next);
    }

    void deleteAtIndex(int index) {
        if (head == nullptr || index < 0) return;

        if (index == 0) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
            return;
        }

        ListNode* cur = head;
        for (int i = 0; cur->next != nullptr && i < index - 1; i++) {
            cur = cur->next;
        }

        if (cur->next == nullptr) return;  // out of range

        ListNode* toDelete = cur->next;
        cur->next = toDelete->next;
        delete toDelete;
    }

    // Optional (good practice): free memory when the list object is destroyed
    ~MyLinkedList() {
        while (head != nullptr) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
};

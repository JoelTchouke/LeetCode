#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* list = malloc(sizeof(MyLinkedList));
    if (!list) return NULL;

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (!obj || index < 0 || index >= obj->size) return -1;

    Node* curr;

    if (index < obj->size / 2) {
        curr = obj->head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
    } else {
        curr = obj->tail;
        for (int i = obj->size - 1; i > index; i--) {
            curr = curr->prev;
        }
    }

    return curr->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    if (!obj) return;

    Node* newNode = malloc(sizeof(Node));
    if (!newNode) return;

    newNode->val = val;
    newNode->prev = NULL;
    newNode->next = obj->head;

    if (obj->head) {
        obj->head->prev = newNode;
    } else {
        obj->tail = newNode;
    }

    obj->head = newNode;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    if (!obj) return;

    Node* newNode = malloc(sizeof(Node));
    if (!newNode) return;

    newNode->val = val;
    newNode->next = NULL;
    newNode->prev = obj->tail;

    if (obj->tail) {
        obj->tail->next = newNode;
    } else {
        obj->head = newNode;
    }

    obj->tail = newNode;
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (!obj || index < 0 || index > obj->size) return;

    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    if (index == obj->size) {
        myLinkedListAddAtTail(obj, val);
        return;
    }

    Node* curr;
    if (index < obj->size / 2) {
        curr = obj->head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
    } else {
        curr = obj->tail;
        for (int i = obj->size - 1; i > index; i--) {
            curr = curr->prev;
        }
    }

    Node* newNode = malloc(sizeof(Node));
    if (!newNode) return;

    newNode->val = val;
    newNode->next = curr;
    newNode->prev = curr->prev;

    curr->prev->next = newNode;
    curr->prev = newNode;

    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (!obj || index < 0 || index >= obj->size) return;

    Node* curr;

    if (index == 0) {
        curr = obj->head;
        obj->head = curr->next;

        if (obj->head) {
            obj->head->prev = NULL;
        } else {
            obj->tail = NULL;
        }

        free(curr);
        obj->size--;
        return;
    }

    if (index == obj->size - 1) {
        curr = obj->tail;
        obj->tail = curr->prev;

        if (obj->tail) {
            obj->tail->next = NULL;
        } else {
            obj->head = NULL;
        }

        free(curr);
        obj->size--;
        return;
    }

    if (index < obj->size / 2) {
        curr = obj->head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
    } else {
        curr = obj->tail;
        for (int i = obj->size - 1; i > index; i--) {
            curr = curr->prev;
        }
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    free(curr);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    if (!obj) return;

    Node* curr = obj->head;
    while (curr) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }

    free(obj);
}
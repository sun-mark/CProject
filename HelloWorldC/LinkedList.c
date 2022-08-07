//
// Created by 蛟龙002 on 2022/8/6.
//
#include "head/io_utils.h"
#include <stdlib.h>

typedef struct Node {
    struct Node *next;
    int i;

} Node;

Node *CreateNode(int value) {
    Node *node = malloc(sizeof(Node));
    if (!node) {
        exit(1);
    }
    node->i = value;
    node->next = NULL;
    return node;
}

void DestroyNode(Node **node_ptr) {
    (*node_ptr)->next = NULL;
    free(*node_ptr);
    *node_ptr = NULL;

}

void removeNode(Node **node_ptr, int index) {
    if (node_ptr == NULL || index < 0 || *node_ptr == NULL) return;
    if (index == 0) {
        Node *new_head = (*node_ptr)->next;
        DestroyNode(&(*node_ptr));
        *node_ptr = new_head;
    }
    while (index != 0) {
        if (--index == 0) {
            //remove node
            Node *current = (*node_ptr)->next;
            Node *next = current->next;
            DestroyNode(&current);
            (*node_ptr)->next = next;
            return;
        }
    }
}

void InsertLinkedNode(Node **node_ptr, int value, int index) {
    if (node_ptr == NULL || index < 0) return;
    if (index == 0) {
        Node *new_node = CreateNode(value);
        new_node->next = *node_ptr;
        *node_ptr = new_node;
    } else {
        Node *current = *node_ptr;
        if (!(*node_ptr)) {
            current = CreateNode(0);
        }
        do {
            if (index == 1) {
                Node *new_node = CreateNode(value);
                new_node->next = current->next;
                current->next = new_node;
                return;
            }
            if (current->next == NULL) {
                current->next = CreateNode(0);
            }
            current = current->next;
        } while ((index--) != 0);
    }
}

Node *CreateLinkedList(int array[], int length) {
    if (length <= 0) {
        return NULL;
    }
    Node *head = CreateNode(array[0]);
    Node *current = head;
    for (int i = 1; i < length; i++) {
        Node *nextNode = CreateNode(i);
        current->next = nextNode;
        current = nextNode;
    }
    return head;
}

void set_node(Node **head_ptr, int index, int value) {
    removeNode(head_ptr, index);
    InsertLinkedNode(head_ptr, value, index);
}

void Println_list(Node *head) {
    if (!head)return;
    Node *current = head;
    while (current) {
        PRINTLN_INT(current->i);
        current = current->next;
    }
}

int main() {
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *head = CreateLinkedList(array, 10);
//    PRINTLN_ARRAY(array, 10);
    Println_list(head);
//    InsertLinkedNode(&head, 2, 12);
//    Println_list(head);
//    DestroyNode(&head);
//    Println_list(head);
//    removeNode(&head, 0);
//    Println_list(head);
    set_node(&head, 3, 5);
    Println_list(head);
    return 0;
}
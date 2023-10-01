// slist.c
#include "slist.h"
#include <stdio.h>
#include <stdlib.h>

// Insert a new node at the end of the list
void insertNode(struct Node** head, int column, char player) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->column = column;
    newNode->player = player;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

// Free the linked list
void freeList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

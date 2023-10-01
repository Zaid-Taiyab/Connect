// slist.h
#ifndef SLIST_H
#define SLIST_H

struct Node {
    int column;
    char player;
    struct Node* next;
};

void insertNode(struct Node** head, int column, char player);
void freeList(struct Node* head);

#endif

#ifndef Limkedlist_h
#define Linkedlist_h
#include <stdio.h>
#include <stdlib.h>

#include "Node.h"

struct LinkedList
{
    struct Node *head;
    int length;

    void(*insert)(int index, void *data, struct LinkedList *LinkedList);
    void(*remove)(int index, struct LinkedList *LinkedList);
    void* (*retrieve)(int index, struct LinkedList *LinkedList);
};


struct LinkedList linked_list_constructor();

#endif
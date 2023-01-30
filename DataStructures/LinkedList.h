#ifndef Limkedlist_h
#define Linkedlist_h
#include <stdio.h>
#include <stdlib.h>

#include "Node.h"

struct LinkedList_int
{
    struct Node_int *head;
    int length;

    void(*insert)(int index, int data, struct LinkedList_int *LinkedList);
    void(*remove)(int index, struct LinkedList_int *LinkedList);
    int(*retrieve)(int index, struct LinkedList_int *LinkedList);
};


struct LinkedList_int linked_list_int_constructor();

#endif
#include "LinkedList.h"
struct Node *create_node(void *data);
void destroy_node(struct Node *node_to_destroy);

struct Node *iterate(int index, struct LinkedList *linked_list);
void insert_node(int index, void *data, struct LinkedList *linked_list);
void remove_node(int index, struct LinkedList *linked_list);
void* retreive_data(int index, struct LinkedList *linked_list);

struct LinkedList linked_list_constructor()
{
    /* data */
    struct LinkedList new_list;
    new_list.head = NULL;
    new_list.length = 0;

    new_list.insert = insert_node;
    new_list.remove = remove_node;
    new_list.retrieve = retreive_data;

    return new_list;
}

struct Node *create_node(void *data)
{
    /* data */
    struct Node *new_node_address = (struct Node *)malloc(sizeof(struct Node));
    struct Node new_node_instance;
    new_node_instance.data = data;
    new_node_instance.next = NULL;
    *new_node_address = new_node_instance;
    return new_node_address;
}

void destroy_node(struct Node *node_to_destroy)
{
    free(node_to_destroy->data);
    free(node_to_destroy);
}
struct Node *iterate(int index, struct LinkedList *linked_list)
{
    /* data */
    if (index < 0 || index > linked_list->length)
    {
        printf("Index out of range: %d\n", index);
        exit(2);
    }
    struct Node *cursor = linked_list->head;
    for (int i = 0; i < index; i++)
    {
        cursor = cursor->next;
    }
    return cursor;
}

void insert_node(int index, void *data, struct LinkedList *linked_list)
{
    struct Node *node_to_insert = create_node(data);
    if (index == 0)
    {
        node_to_insert->next = linked_list->head;
        linked_list->head = node_to_insert;
    }
    else
    {
        struct Node *cursor = iterate(index - 1, linked_list);
        node_to_insert->next = cursor->next;
        cursor->next = node_to_insert;
    }
    linked_list->length += 1;
}

void remove_node(int index, struct LinkedList *linked_list)
{
    if (index == 0)
    {
        struct Node *node_to_remove = linked_list->head;
        linked_list->head = node_to_remove->next;
        destroy_node(node_to_remove);
    }
    else
    {
        struct Node *cursor = iterate(index - 1, linked_list);
        struct Node *node_to_remove = cursor->next;
        cursor->next = node_to_remove->next;
        destroy_node(node_to_remove);
    }
    linked_list->length -= 1;
}

void* retreive_data(int index, struct LinkedList *linked_list)
{
    struct Node *cursor = iterate(index, linked_list);
    return cursor->data;
}

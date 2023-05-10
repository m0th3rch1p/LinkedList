#include <stdio.h>
#include "DataStructures/LinkedList.h"

int main()
{
    struct LinkedList list = linked_list_constructor();

    for (int i = 0; i < 12; i++)
    {
        int *x = (int *)malloc(sizeof(int));
        *x = i;
        list.insert(i, x, &list);
    }
    int *y=(int *)malloc(sizeof(int));
    *y=99;
    list.insert(list.length, y, &list);
    list.remove(3, &list);
    list.remove(7, &list);

    for (int i = 0; i < list.length; i++)
    {
        printf("%d\n", *(int *)list.retrieve(i, &list));
    }
}

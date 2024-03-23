#include <stdio.h>
#include <string.h>
#define MAX 100

struct Item{
    int id;
    char name[MAX];
    long phone_no;
};

struct List{
    struct Item items[MAX];
    int size;
};

void addItems(struct List *list, struct Item newitem)
{
    if(list->size<MAX)
    {
        list->items[list->size++]=newitem;
        printf("Item added Successfully\n");
    }

    else
    {
        printf("List is not empty.\n");
    }
}

void display(struct List newlist)
{
    int i;
    for(i=0; i<newlist.size; i++)
    {
        printf("Id=%d, Name=%s, Phone=%ld\n", newlist.items[i].id, newlist.items[i].name, newlist.items[i].phone_no);
    }
}

int main()
{
    struct List newList;
    newList.size=0;

    struct Item c1={1,"Hem", 9800012345};
    addItems(&newList, c1);
    struct Item c2={2,"Pooja", 9826032145};
    addItems(&newList, c2);
    printf("%d\n", newList.size);
    display(newList);
    return 0;
}
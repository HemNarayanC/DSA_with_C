#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

int main()
{
    struct node *head=NULL;
    head=(struct node *)malloc(sizeof(struct node));

    head->info=60;
    head->link=NULL;

    printf("%d", head->info);
    return 0;
}
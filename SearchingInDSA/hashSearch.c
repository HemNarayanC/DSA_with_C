
//Chaining Implementation for demo dictionary application

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define HASH_SIZE 26
#define WORD_SIZE 50
#define MEANING_SIZE 100
struct item{
    char word[WORD_SIZE];
    char meaning[MEANING_SIZE];
};

struct node{
    struct item myWord;
    struct node*next;
};

struct node header[HASH_SIZE];      //hash table of size HASH_SIZE
struct node *getnode(struct item w)
{
    struct node *ptrnew;
    ptrnew=(struct node *)malloc(sizeof(struct node));
    if(ptrnew==NULL)
    {
        printf("Memory Allocation Failed");
        getch();
        exit(0);
    }
    ptrnew->myWord=w;       //store word into myWord field
    ptrnew->next=NULL;      //set next field to NULL
    return ptrnew;
}

void add()
{
    struct item key;
    struct node *ptrnew;
    int index;
    printf("\nEnter a word or phrase: ");
    fflush(stdin);
    gets(key.word);
    printf("\nEnter its meaning");
    fflush(stdin);
    gets(key.meaning);
    ptrnew=getnode(key);
    index=toupper(key.word[0])-65;     //get the ascii value of first letter in the
    ptrnew->next=header[index].next;        //point to the first item in the list
    header[index].next=ptrnew;      //insert at the front of the list
    printf("Word Added Successfully."); 

}

void search()
{
    char key[WORD_SIZE];
    int index;
    struct node *ptrthis;
    printf("\nEnter a word you want to search: ");
    fflush(stdin);
    gets(key);
    index=toupper(key[0])-65;
    for(ptrthis=header[index].next; ptrthis!=NULL; ptrthis=ptrthis->next)
    {
        if(strcmpi(ptrthis->myWord.word, key)==0)     //if matched
        {
            printf("\nWord: %s", ptrthis->myWord.word);
            printf("\nMeaning: %s", ptrthis->myWord.meaning);
            return;
        }
    }
    printf("%s does not exist in the dictionary.", key);
}

void list()
{
    int i;
    struct node *ptrthis;
    printf("Dictionary contains: ");
    for(i=0; i<HASH_SIZE; i++)
    {
        if(header[i].next!=NULL)        //if there is word in the list
        {
            printf("\nAlphabet: %c", i+65);
            for(ptrthis=header[i].next; ptrthis!=NULL; ptrthis=ptrthis->next)
                printf("%s, ",ptrthis->myWord.word);
        }
    }
}

void main()
{
    char choice;
    int i;
    for(i=0; i<HASH_SIZE; i++)
    {
        header[i].next=NULL;        //initialize the header field's next to NULL
    }
    do{
        printf("Select an option: \n1.Add word\n2. Search Word\n3.Lis\n4.Exit");
        fflush(stdin);
        choice=getche();
        switch(choice){
            case '1': 
                    add();
                    break;
            case '2': 
                    search();
                    break;
            case '3': list();
                        break;
            case '4': return;
        }
        getch();
    }while(1);
}
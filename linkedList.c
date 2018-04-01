


#include <stdlib.h>
#include <stdio.h>


typedef struct node{
    int data;
    struct node *next;
} Node;


typedef struct {
    Node *head;
} List;


void addNode(List *lst,int data);
void printList(List *lst);
int sumList(List *lst);


void freeNode(List *lst)
;

int main()
{
    List lst;
    lst.head = NULL;
    int i;

    for (i=0; i<35; i++)
    {
        addNode(&lst,i);
    }

    printList(&lst);


    printf("\nthe sum is %d\n",sumList(&lst));

    freeNode(&lst);
    return 0;
}


void freeNode(List *lst)
{
    Node *toDelete;

    while (lst->head != NULL)
    {
        toDelete = lst->head;
        lst->head = toDelete->next;
        free(toDelete);
    }
    printf("free bitch!\n");
}



void printList(List *lst)
{
    Node *currentNode = lst->head;

    while (currentNode != NULL)
    {
        printf("%d\t",currentNode->data);
        currentNode = currentNode->next;
    }
}

void addNode(List *lst, int data)
{
    Node *newNode = (Node*) malloc(sizeof(Node));

    newNode->data = data;

    newNode->next = lst->head;
    lst->head = newNode;
}


int sumList(List *lst) {
    Node *currentNode = lst->head;

    int sum = 0;


    while (currentNode != NULL)
    {
        sum+=currentNode->data;

        currentNode = currentNode->next;
    }

    return sum;
}

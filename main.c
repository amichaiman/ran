#include <stdio.h>

typedef struct node{
    int value;
    struct node *next;
} Node;

void print_spot(Node *head, int indexToPrint);
void print_linked_list(Node *head);
void remove_node(Node *current, int value);

int main() {
    //13-32 איתחול של הנודים
    Node node1;
    Node node2;
    Node node3;
    Node node4;
    Node node5;

    Node *current;

    node1.value = 2;
    node2.value = 9;
    node3.value = -13;
    node4.value = 113;
    node5.value = -123;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;


    //print_spot(&node1,2);

    print_linked_list(&node1);  //הדפסת הרשימה
    remove_node(&node1,13);  //מחיקת האיבר בעל הערך 13
    print_linked_list(&node1);  //הדפסת הרשימה
}


void print_linked_list(Node *head)
{
    while (head != NULL)
    {
        printf("%d\t",head->value); //printf current
        head = head->next;          //go to next
    }
    putchar('\n');
}

//מדפיס את האיבר הx ברשימה
void print_spot(Node *head, int indexToPrint)
{
    int i;

    //תעבור להבא x פעמים
    for (i=0; i<indexToPrint; i++)
    {
        head = (*head).next;
    }

    printf("%d\n",(*head).value);
}

/*
 *האלגוריתם הולך ככה:
 * אם האיבר הבא הוא מי שאני רוצה למחוק אז
 * הבא של הנוכחי הוא ההבא של ההבא
 */
void remove_node(Node *current, int value)
{
    while (current->next != NULL && current->next->value != value)
    {
        current = current->next;
    }
    if (current->next != NULL)
    {
        current->next = current->next->next;
    }
    else
    {
        printf("element not found!\n");
    }
}

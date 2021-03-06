<<<<<<< HEAD
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
=======
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "stdio.h"
#define MAX_LEN 5


char *dup_letters_by_digits(char *letters, char *digits);

int main(){
    char letters[] = "neta";
    char digits[] = "2314";
    char *new_array = NULL;

    new_array = dup_letters_by_digits(letters,digits);

    printf("%s\n",new_array);
    return 0;
}



/**************************************************************
 * function will duplicate each letter in spot i in array
 * 'letters' as many times as written in digits array in spot
 * i.
 *
 * input: array of digits to be duplicated, array of digits.
 * output: new array dynamicaly allocated containing new
 * string
 **************************************************************/

char *dup_letters_by_digits(char *letters, char *digits){
    int i,j;        //loops index
    int len_letters, len_digits, len_new_arrray = 0;
    char *new_array;            //will contain new array
    int spot_in_new_array = 0;

    len_letters = strlen(letters);
    len_digits = strlen(digits);

    // arrays must be same length && their length must be under 'MAX_LEN'
    if (len_digits != len_letters || len_digits > MAX_LEN || len_letters > MAX_LEN){
        return NULL;
    }


    //'letters' must contain letters only and 'digits' must contain digits only
    for (i=0; i<len_letters; i++){
        if (!isalpha(letters[i]) || !isdigit(digits[i])){
            return NULL;
        }
    }

    //length of new array is determined by the sum of digits in 'digits' array
    for (i=0; i<len_digits; i++){
        len_new_arrray += digits[i] - '0';
    }

    new_array = (char *) malloc ((len_new_arrray+1)* sizeof(char));

    //i indicates the current letter and its currisponding digits
    for (i=0; i<len_letters; i++){
        for (j=0; j<digits[i]-'0'; j++){    //loops runs digits[i] times
            new_array[spot_in_new_array++] = letters[i];    //spot in new array currently being written to
        }
    }

    new_array[spot_in_new_array] = '\0';

    return new_array;
}
>>>>>>> 1476581d906e65f27221f3f8bfd77fe78616ad1a

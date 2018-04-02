#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define QUIT 7

typedef struct {
    char id[SIZE];
    char name[SIZE];
    char last_name[SIZE];
    char dob[SIZE];
} Student;

//הנוד תמיד יראה קבוע. למעלה מצביע לתוכן. ולמטה מצביע לתא הבא
typedef struct node {
    Student *student;
    struct node *next;
} Node;


typedef struct {
    Node *head;
} List;

Student *getStudent();
Node *addNode(List *lst);
void instuctions();
void printStudent(Student *toPrint);
void printList(List *lst);
int numberOfStudents(List *lst);

int main()
{
    List lst;
    lst.head = NULL;


    int input;

    instuctions();
    scanf("%d",&input);


    while (input != QUIT)
    {
        switch (input)
        {
            case 1:
                addNode(&lst);
                break;
            case 2:
                printf("----------------------------------\n");
                printf("you have here %d students\n",numberOfStudents(&lst));
                printf("----------------------------------\n");
                break;
            case 4:
                printList(&lst);
                break;

            default:
                printf("invalid option\n");
        }
        instuctions();
        scanf("%d",&input);

    }


    return 0;
}

void printList(List *lst)
{
    Node *currentNode;
    currentNode=lst->head;
    while(currentNode!=NULL)
    {
        printf("----------------------------------\n");
        printStudent(currentNode->student);
        printf("----------------------------------\n");
        currentNode=currentNode->next;
    }

}

//פונקציה זו תדפיס את הנתונים של סטודנט
void printStudent(Student *toPrint)
{
    printf("ID:            %18s\n",toPrint->id);
    printf("Name:          %18s\n",toPrint->name);
    printf("Last Name:     %18s\n",toPrint->last_name);
    printf("Date of birth: %18s\n",toPrint->dob);
}
//מדפיסה את האפשרויות למשתמש
void instuctions()
{
    printf("-------------------------------------------------------\n");
    printf("WELCOME TO RAN'S HIGH SCHOOL! WHAT DO YOU WISH TO DO?\n");
    printf("1\t Add student\n");
    printf("2\t print the number of the student\n");  // זה המניה של הסטראקטים
    printf("4\t Print list\n");
    printf("7\t QUIT\n");
    printf("-------------------------------------------------------\n");

}


int numberOfStudents(List *lst)
{
    int sum = 0;
    Node *currentNode;
    currentNode=lst->head;
    while(currentNode!=NULL)
    {
        sum++;
        currentNode=currentNode->next;
    }

    return sum;
}

Student *getStudent() {
    Student *newStudent;

    newStudent = (Student*) malloc (sizeof(Student));


    printf("ENTER STUDENT DETAILS:\n");

    printf("enter name:\n");
    scanf("%s",&newStudent->name);

    printf("enter last name:\n");
    scanf("%s",&newStudent->last_name);

    printf("enter id:\n");
    scanf("%s",&newStudent->id);

    printf("enter date of birth:\n");
    scanf("%s",&newStudent->dob);

    return newStudent;
}

Node *addNode(List *lst) {
    Node *newNode;

    newNode = (Node*) malloc(sizeof(Node));
    newNode->student = getStudent();

    newNode->next = lst->head;
    lst->head = newNode;

    return newNode;

}

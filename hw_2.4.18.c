#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define SIZE 10
#define QUIT 6

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
void updateStudent(List *lst);
void removeNode(List *lst);

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
                removeNode(&lst);
                break;
            case 3:
                updateStudent(&lst);
                break;
            case 4:
                printf("----------------------------------\n");
                printf("you have here %d students\n",numberOfStudents(&lst));
                printf("----------------------------------\n");
                break;
            case 5:
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

void removeNode(List *lst)
{
    char toFind[SIZE]; //  יצרנו צ'אר ארעי שאיתו נבדוק את האיי דיאים בכל הסטראקטים של הסטודנטים

    printf("Enter the students' ID you would like to remove:\n");
    scanf("%s", toFind);

    Node *currentNode = lst->head; //יוצרים נואוד ארעי שאליו נשווה

    //ראשית נטפל במקרה הקצה בו התא הראשון הוא האיי די שנרצה להסיר
    if (strcmp(toFind, currentNode->student->id) == 0) //בודקים את האיי די של הסטודנט של הקרנטנואוד הבא - לא של הנוכחי, למה? בהמשך נבין
    {
        lst->head=currentNode->next;  //במצב כזה אני עושה מעקף בו ההדר יפנה לשני
        free(currentNode); //ואת הראשון פשוט נמחק
        return;//ויוצאים מהפונקציה
    }


    while(currentNode->next!=NULL)
    {
        if (strcmp(toFind, currentNode->next->student->id) == 0) //בודקים את האיי די של הסטודנט של הקרנטנואוד הבא - לא של הנוכחי, למה? בהמשך נבין
        {
            Node *toDelete = currentNode->next; //יוצר מתשנה זמני שיכיל את מי שאני מוחק
            currentNode->next = currentNode->next->next; //מבצע מעקף לכתובת הבאה
            free(toDelete);
            return;
        } else
            currentNode = currentNode->next;
    //אם הגענו לסוף הפונקציה סימן שלא עשינו ריטרן
        printf("wrong id!\n");
    }
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
    printf("2\t Delete student\n");
    printf("3\t Update student info\n");
    printf("4\t print the number of the student\n");  // זה המניה של הסטראקטים
    printf("5\t Print list\n");
    printf("6\t QUIT\n");
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

void updateStudent(List *lst) //מקבל מהמיין את הכתובת של הליסט
{

    char toUpdate[SIZE];

    printf("Enter the students' id you want to update:\n");

    scanf("%s",toUpdate);


    Node *currentNode = lst->head; //מצביע כל פעם לנוד אחד ברשימה
    while(currentNode!=NULL)    //לא הגענו לסוף
    {
        if(strcmp(toUpdate,currentNode->student->id)==0) //אם הנוד הנוכחי זה מי שאני רוצה לעדכן
        {
            printf("Enter new info:\n");
            free(currentNode->student);         //מוחק את הישן

            currentNode->student = getStudent();    //שם חדש! וואו משהו משהו אוקיי אוקיי אןקיי
            return;
        }
        currentNode=currentNode->next;
    }
    printf("\ninvalid id, try again\n\n");
}
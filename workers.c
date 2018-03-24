#include <stdio.h>
#include <stdlib.h> //בשביל הקאלוק
#define N 7
#define COLS 3  //caps

void make_start_and_end_hours(int start, int end, int *arr); //כדי להעביר את המטריצה למערך של 24
void ok_at_press_hour(int* arr);//כדי לבדוק אם הכל בסדר בשעות הלחץ
void print_matrix(int mat[][COLS], int lines);//סתם כדי להדפיס את המטריצה

int main()
{
    int mat[N][3];
    int i;
    int* arr;  //משריין מקום בהיפ
    
    arr=(int*)calloc(24,sizeof(int)); //משריין מקום ל-24 תאים מאופסים
    
    for(i=0 ; i<N ; i++)
    {   
        printf("Enter the worker number: ");
        scanf("%d",&mat[i][0]);
        
        printf("When did he start to work? ");
        scanf("%d", &mat[i][1]);
        
        printf("When did he end? ");        
        scanf("%d",&mat[i][2]);
    }
    
    print_matrix(mat,7);    //only mat
        
    for(i=0 ; i<N ; i++)
        make_start_and_end_hours(mat[i][1],mat[i][2], arr);   
    //כעת יש לי בהיפ מערך עם 24 תאים עם נתוני שעות העבודה בשעת הלחץ
    
    ok_at_press_hour(arr);
    
    free(arr);
    
    return 0;
}

void print_matrix(int mat[][COLS], int lines)
{
    int i,j;
    for(i=0 ; i<lines ; i++)
        {
            for(j=0 ; j<COLS ; j++)
                {
                    printf("%3d", mat[i][j]);
                }
            printf("\n");
        }    
}

void make_start_and_end_hours(int start, int end, int *arr)
{
    int i,j;
    for(i=start ; i<end ; i++)
        arr[i]++;  
}

void ok_at_press_hour(int* arr)
{
    int i;
    int flag=1; //פלאג אחד אומר שהכל בסדרת אם ישתנה לאפס נדע שיש בעיה
    
    for(i=8 ; i<17 ; i++)  //לשעת הלחץ הראשונה
        if(arr[i]<3)
        {
            flag=0;
            printf("missing %d workers at %d\n", 3-arr[i], i);
        }
            
    for(i=17 ; i<24 ; i++) //לחלק א של שעת הלחץ השניה
        if(arr[i]<2)
        {
            flag=0;
            printf("missing %d workers at %d\n", 2-arr[i], i);
        }
    
     for(i=0 ; i<8 ; i++) // לחלק ב של שעת הלחץ השניה
        if(arr[i]<2)
        {
            flag=0;
            printf("missing %d workers at %d\n", 2-arr[i], i);
        }
    if(flag==1)
        printf("yes!\n");
    
}

#include <stdio.h>


/******************************************************
 * winter 2016 q2
 *
 *
           התוכנית תשים במערך arr2 במקום הi את האינדקס של
 הערך הראשון בarr1 שקטן ממנו
 *
                                              לפני:
 *              {25, 20, 15, 10, 9, 7, 5, 3, 2, -1}
 *              {30, 4, 15, 1, -1}
 *
                אחרי:
 *              {25, 20, 15, 10, 9, 7, 5, 3, 2, -1}
 *              {0, 7, 3, 9, -1}
 *
 *
 * program sends 2 arrays to function.
 *
 * function will change arr2 as following:
 * arr2 in spot i gets the index of the first number
 * in arr1 that is smaller than it
 *

 ********************************************************/

void print_array(int arr[]);

void func(int *arr1, int *arr2);

int main(){
    int arr1[] = {25,20,15,10,9,7,5,3,2,-1};
    int arr2[] = {30,4,15,1,-1};

    printf("before:\n");
    print_array(arr1);
    print_array(arr2);

    func(arr1, arr2);

    printf("after:\n");
    print_array(arr1);
    print_array(arr2);
}



/****************************************
        פונקציה שמדפיסה את המערך
 * prints array
 *
 *****************************************/
void print_array(int arr[]){
    int i;

    printf("{");
    for (i=0; arr[i] != -1; i++){
        printf("%d, ",arr[i]);
    }
    printf("-1}\n");
}


/************************************************
 *
      הפונקציה תשים במקום הi בarr2 את האינדקס של
      התא הראשון בarr1 שהערך שלו קטן ממנו
 *
 *
 *
 * arr2 in spot i gets the index of the first number
 * in arr1 that is smaller than it
 *
 * input: 2 arrays
 * output: none
 ************************************************/
void func(int *arr1, int *arr2){
    int i,j;

    for (i=0; arr2[i] != -1; i++){
        for (j=0; arr1[j] >= arr2[i]; j++); // הערך של j גדל כל עוד הערל במקום הj במערך הראשון גדול מהמקום הi במערך השני

        arr2[i] = j;    //האינדקס של האיבר הראשון בarr2 שקטן מהתא שאנו בודקים
    }
}
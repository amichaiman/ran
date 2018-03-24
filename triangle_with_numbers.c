#include <stdio.h>
/***********************************************
 * program prints piramid of numbers.
 * example:
 * user enters number 4
 * output:
 *     1
 *    121
 *   12321
 *  1234321
 ************************************************/
void print_triangle(int n);
void print_numbers(int n);
void print_spaces(int n);

int main(){
    int n;

    printf("enter num:\n");
    scanf("%d",&n);

    print_triangle(n);
}

void print_triangle(int n) {
    int i;

    for (i=0; i<n; i++){
        print_spaces(n-1-i);
        print_numbers(i+1);
        printf("\n");
    }
}
/***************************
 * prints numbers as following:
 * for input 3, output is:
 * 1 2 3 2 1
 ***************************/
void print_numbers(int n){
    int i;

    for (i=1; i<=n; i++) {
        printf("%d", i);
    }
    for (i=n-1; i>0; i--){
        printf("%d",i);
    }
}
/********************************
 * prints n amount of spaces
 ******************************/
void print_spaces(int n){
    int i;

    for (i=0; i<n; i++){
        printf(" ");
    }
}
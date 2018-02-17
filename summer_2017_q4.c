#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 20
/**********************************************
 * program receives string from user
 * if string makes a legal mathematical phrase
 *
 * "yup it's legal" is printed to screen
 * else
 * "nope its not legal" is printed
 *
 *
 *
 *
 * legal phrase:
 *      before and after a char
 *      from the group + - * / =
 *      must appear a digit
 *      the char = must appear once only
 *
 *
 *
 *
 * example:
 * "123+1233=123" is legal
 * "1+1-34=34234+3" is legal
 *
 * "123+123" is not legal
 * "1-1+34-123=" is not legal
 *********************************************/
int is_legal_calc_phrase(char *a);

int main(){
    char phrase[MAX_LEN+1];

    printf("Enter phrase to calculate:\n");
    scanf("%s",&phrase);


    if (is_legal_calc_phrase(phrase)){
        printf("yup it's legal");
    } else {
        printf("nope it's not legal");
    }

    return 0;
}



int is_legal_calc_phrase(char *a){

    int len = strlen(a);
    int i=0;
    int equal_sign_flag = 0;

    if (!isdigit(a[0])  || !isdigit(a[len-1])){  //first and last characters must be digits
        return 0;
    }

    for (i=0; i<len; i++){
        if (!isdigit(a[i])){

            if (a[i] == '-' ||  a[i] == '+' || a[i] == '*' || a[i] == '/'){
                if (!isdigit(i-1) || !isdigit(i+1)){    //must be surrounded by digits
                    return 0;
                }
            } else if (a[i] == '='){
                if (equal_sign_flag == 1){  //if '=' already appeared
                    return 0;
                }
                else {
                    equal_sign_flag = 1;
                }
            } else {    //if it is not a digit and not +-/* or =
                return 0;
            }
        }
    }

    if (equal_sign_flag == 1){  //'=' must appear once
        return 1;
    }
    return 0;
}
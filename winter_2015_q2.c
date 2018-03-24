#include <stdio.h>  //puts
#include <string.h> //strlen
#include <ctype.h>  //isalpha, isspace
#include <malloc.h> //malloc

/********************************************
 * program sends string to function.
 *
 * the function allocates memory for new
 * string and copied it as following:
 *
 * # if the string contains the number 1,
 * the following char will be copied twice.
 *
 * # if the number is 0 the following char
 * will be ignored.
 *
 * # letters and spaces are copied as is.
 * *****************************************/

char *func(char *str);

int main()
{
    char str[] = "ha1py0f w1ek0gen0hd";
    char *new_str = NULL;               //pointer to new string

    new_str = func(str);

    puts(new_str);                      //pring new string
    return 0;
}


/*****************************************
 * the function allocates memory for new
 * string and copied it as following:
 *
 * # if the string contains the number 1,
 * the following char will be copied twice.
 *
 * # if the number is 0 the following char
 * will be ignored.
 *
 * # letters and spaces are copied as is.
 *
 *
 * input: string.
 * output: new string dynamically allocated
 ****************************************/

char *func(char *str) {
    char *new_str = NULL;       //will hold new string
    int len_of_new_str = 0;     //will hold length of new string
    int spot_in_new_array = 0;  //will hold index of current spot to write to in new string
    int len_of_str;             //length of the given string
    int i;                      //loop index

    len_of_str = strlen(str);

    for (i=0; i<len_of_str; i++){
        if (isalpha(str[i]) || isspace(str[i])){       //if str[i] is a letter or a space, add one spot to new str
            len_of_new_str++;
        } else {    //it must be 0 or 1
            if (str[i] == '1') {  //if str[i] is the char '1', add two spots to new str
                len_of_new_str += 2;
            }
            i+=1;                   //jump over next char
        }
    }

    new_str = (char *) malloc((len_of_new_str+1)* sizeof(char));    // +1 for NULL terminator

    for (i=0; i<len_of_str; i++){
        if (isalpha(str[i]) || isspace(str[i])) {       //if str[i] is a letter or a space, copy it as is
            new_str[spot_in_new_array++] = str[i];
        } else {    //it must be 0 or 1
            if (str[i] == '1') {                       //if str[i] is the char '1' copy str[i+1] twice
                new_str[spot_in_new_array++] = str[i + 1];
                new_str[spot_in_new_array++] = str[i + 1];
            }
            i+=1;                                       //skip next char in str[]
        }
    }

    new_str[len_of_new_str] = '\0'; // don't forget!

    return  new_str;    //return address of new allocated string
}
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define N 4
#define MAX 50

void from_char_to_(char *str);

int main()
{
    char str1[MAX],str2[MAX],str3[MAX],str4[MAX]; 
    int size1,size2,size3,size4;
    int size; 
    char *str; //המחרוזת שתכיל את כל המחרזות שקלטנו ותישמר בהיפ
    int i;
    
    printf("Enter %d strings:\n",N);  //מבקשים להכניס 4 מחרוזות וקולטים אותם
    fgets(str1,MAX,stdin);
    fgets(str2,MAX,stdin);
    fgets(str3,MAX,stdin);
    fgets(str4,MAX,stdin);
    
    str1[strcspn(str1,"\n")] = '\0';
    str2[strcspn(str2,"\n")] = '\0';
    str3[strcspn(str3,"\n")] = '\0';
    str4[strcspn(str4,"\n")] = '\0';
    
    size1=strlen(str1);
    size2=strlen(str2);
    size3=strlen(str3);
    size4=strlen(str4);
    size=size1+size2+size3+size4+1;
    
    //מייעדים מקום בהיפ בעזרת מאלוק ובעזרת השם לסטרינג החדשה שתכיל את כולם
    str=(char*)malloc(size*sizeof(char));
    if(str==NULL)
        printf("Sorry, there is no enough place on memory");
        
    //משרשרים את המחרוזות הקיימות לאחת גדולה אחרי שכבר יש לה מקום בהיפ
    strcpy(str,str1);   //copy
    strcat(str,str2);
    strcat(str,str3);
    strcat(str,str4);
    
    //כעת משנים את כל האותיות לקטנות ואת התווים לקו תחתון
    for(i=0 ; i<size-1 ; i++)
    {
        if(isalpha(str[i]))      //אם זו אות
            tolower(str[i]);     //תקטין אותה
        else                     //אם זו לא אות
            str[i]='_';   //שנה אותה לקו תחתון
    }
    
    puts(str);
    
    return 0;
}
/*
void from_char_to_(char *str)
{
    int i, res, size=strlen(str);
    
    for(i=0 ; i<size ; i++)
        {
            res=isalpha(str[i]);  //אם זה לא אות יכנס לרז אפס
            if(res==0)
                str[i]=_;
        } 
}*/

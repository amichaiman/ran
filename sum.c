#include <stdio.h>
#define N 3

int bool_funcA(int mat[][N], int size);      //הפונקציה מחזירה אחד אם הסכומים שווים אפס אם לא
int sum_up_diagonals(int mat[][N], int line);
int sum_down_diagonals(int mat[][N], int line);

int main()
{
    int mat[N][N];
    int i,j; //for loop index
    int res;
    
    printf("Enter %d to the matrix\n", N*N);
    
    for(i=0 ; i<N ; i++)
        for(j=0 ; j<N ; j++)
            scanf("%d", &mat[i][j]);
    
    
    res = bool_funcA(mat, N);
    
    if(res)
        printf("equal\n");
    else
        printf("unequal\n");
    
        
    return 0;
}

int sum_up_diagonals(int mat[][N], int line)
{
    int i,j, sum=0;
    
    for(i=0 ; i<line ; i++)
        for(j=i+1 ; j<line ; j++)
            sum=sum+mat[i][j];
    return sum;
}

int sum_down_diagonals(int mat[][N], int line)
{
    int i,j, sum=0;
    
    for(i=0 ; i<line ; i++)
        for(j=0 ; j<i ; j++)
            sum=sum+mat[i][j];
    return sum;
}

int bool_funcA(int mat[][N], int size)
{
    int sumUp=sum_up_diagonals(mat, size);
    int sumDown=sum_down_diagonals(mat,size);
    if(sumUp==sumDown)
        return 1;
    return 0;
}

#include <stdio.h>
#define N 4
/*****************************************
 * an even matrix is defined as following:
 *
 * # count number of 1's in the row (besides
 *   the last) and check the following:
 *
 *   1) if the number of 1's is
 *      even, the last must be 0.
 *
 *   2) if the number of 1's is
 *      uneven, the last must be 1
 *
 * # count number of 1's in the column
 *   (besides  the last) and check the
 *   following:
 *
 *   1) if the number of 1's is
 *      even, the last must be 0.
 *
 *   2) if the number of 1's is
 *      uneven, the last must be 1
 *
 *  program calls a function that checks
 *  whether the the matrix is even or not
 *  and prints message to standard output
 *  accordingly
 **************************************/

int sum_of_col_is_even(int mat[][N], int col);
int is_legal_matrix(int mat[][N]);
int sum_of_row_is_even(int row[]);
int is_even_matrix(int mat[][N]);

int main(){
    int mat[N][N] = {{0,1,0,1},{1,1,1,1},{1,0,0,1},{0,0,1,0}};

    if (is_even_matrix(mat)){
        printf("matrix is even\n");
    } else {
        printf("matrix is uneven\n");
    }
    return 0;
}


/****************************************************
 * function checks whether a given matrix is even.
 *
 * input: matrix
 * output: 1 if the matrix is eve, 0 otherwise.
 * **************************************************/
int is_even_matrix(int mat[][N]){
    int i;

    if (!is_legal_matrix(mat)){ //if matrix doesn't contain 0's and 1's only
        return 0;
    }

    /*  checking that rows are legal */
    for (i=0; i<N-1; i++){
        if (sum_of_row_is_even(mat[i])) {
            if (mat[i][N-1] != 0) {     //if sum of row is even, last spot must be 0
                return 0;
            }
        } else {
            if (mat[i][N-1] != 1){      //if sum of row is uneven, last spot must be 1
                return 0;
            }
        }
    }

    /*  checking that columns are legal */
    for (i=0; i<N-1; i++){
        if (sum_of_col_is_even(mat, i)){
            if (mat[N-1][i] != 0){      //if sum of column is even, last spot must be 0;
                return 0;
            }
        } else {
            if (mat[N-1][i] != 1){      //if sum of column is uneven, last spot must be 1
                return 0;
            }
        }
    }

    return 1;
}

/***************************************
 * function checks whether the number
 * of 1's in given row is even or not
 *
 * input: array of binary numbers.
 * output: 1 if row has even number
 *         of 1's, 0 otherwise.
 ***************************************/
int sum_of_row_is_even(int row[]){
    int i;
    int sum=0;

    /*  for loop sums number of 1's in row (besides the last spot)  */
    for (i=0; i<N-1; i++){
        sum+=row[i];
    }

    return sum%2 == 0;  //1 if sum is even, 0 otherwise
}



/***************************************
 * function checks whether the number
 * of 1's in given column is even or not
 *
 * input: array of binary numbers.
 * output: 1 if column has even number
 *         of 1's, 0 otherwise.
 ***************************************/
int sum_of_col_is_even(int mat[][N], int col){
    int i;
    int sum=0;

    /*  for loop sums number of 1's in column (besides the last spot)  */
    for (i=0; i<N-1; i++){
        sum += mat[i][col];
    }

    return sum%2 == 0;  //1 if sum is even, 0 otherwise
}


/*****************************************
 * function checks whether given matrix
 * contains the numbers 1 and 0 only.
 *
 * input: matrix of numbers
 * output: 1 if matrix contains 1
 *         and 0 only, 0 otherwise.
 ****************************************/
int is_legal_matrix(int mat[][N]){
    int i,j;

    for (i=0; i<N; i++){
        for (j=0; j<N; j++) {
            if (mat[i][j] != 0 && mat[i][j] != 1) { //if current index isn't 1 and isn't 0
                return 0;
            }
        }
    }
    return 1;
}
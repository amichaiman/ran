#include <stdio.h>
#define N 5
/*********************************************
 * winter 2014 q4
 *
 * program will find seqences is desired
 * length and will print the starting index
 * to standard output
 * ******************************************/


void find_seq_in_row(int row[], int wanted_seq_len, int cur_row_num);

void print_seq_indexs_in_matrix(int mat[][N], int wanted_seq_len);

void find_seq_in_col(int mat[][N], int cur_col, int wanted_seq_len);

int main(){
    int mat[N][N] = {{1,2,3,4,5},
                    {1,1,1,1,1},
                    {1,4,5,6,7},
                    {1,5,6,7,8},
                    {5,6,7,8,9}};

    print_seq_indexs_in_matrix(mat,4);
    return 0;
}




/**********************************
 * function searches for sequences
 * in rows and in columns. if found,
 * starting sequence indexs will be
 * printed to standard output
 *
 * input: matrix of numbers, desired
 *        desired sequence length
 *
 * output: none
 * *********************************/
void print_seq_indexs_in_matrix(int mat[][N], int wanted_seq_len) {
    int i;

    for (i=0; i<N; i++){
        find_seq_in_row(mat[i],wanted_seq_len,i);
        find_seq_in_col(mat,i,wanted_seq_len);
    }
}


/*************************************
 * function searches for sequence
 * in 1d array. if found, starting
 * index is printed to standard output
 *
 * input: int array, desired sequence
 *        length, current row in
 *        original matrix
 *
 * output: none
 *************************************/

void find_seq_in_row(int row[], int wanted_seq_len, int cur_row_num) {
    int i;
    int cur_seq_len = 1;

    for (i=1; i<N; i++){
        if (row[i] == row[i-1]){
            cur_seq_len++;
            if (cur_seq_len == wanted_seq_len){
                printf("sequence found at mat[%d][%d]\n",cur_row_num,i-(wanted_seq_len-1));
                cur_seq_len--;
            }
        } else {
            cur_seq_len = 1;
        }
    }
}


/********************************
 * function searches for sequence
 * in matrix columns. if found,
 * starting indexs are printed
 * to standard output.
 *
 * input: matrix, column to search
 *        in, wanted sequence len
 *
 * output: none
 **********************************/
void find_seq_in_col(int mat[][N], int cur_col, int wanted_seq_len){
    int i;
    int cur_seq_len = 1;

    for (i=1; i<N; i++){
        if (mat[i][cur_col] == mat[i-1][cur_col]){
            cur_seq_len++;
            if (cur_seq_len == wanted_seq_len) {
                printf("sequence found at mat[%d][%d]\n", i-wanted_seq_len+1, cur_col);
                cur_seq_len--;
            }
        } else {
            cur_seq_len = 1;
        }
    }
}
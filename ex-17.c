//
// Created by vinniciusj on 15/08/23.
//
#include<stdio.h>
#include <errno.h>

#define MAX_LOC 100

typedef struct {
    int row;
    int column;
} MATRIX_COORD;

void fill_matrix(int matrix[][MAX_LOC], MATRIX_COORD limit){
    for(int i = 0; i < limit.row; i++){
        for(int j = 0; j < limit.column; j++){
            matrix[i][j] = 1;
        }
    }
}

void zero_matrix(int matrix[][MAX_LOC], MATRIX_COORD * coords, int coords_length){
    for(int i = 0; i < coords_length; coords++, i++){
        matrix[coords->row][coords->column] = 0;
    }
}

void read_zero_coords(MATRIX_COORD * coords, int length){
    for(int i = 0; i < length; i++, coords++){
        scanf("%d %d", &coords->row, &coords->column);
    }
}

int print_matrix(int matrix[][MAX_LOC], MATRIX_COORD limit){
    FILE * file;

    file = fopen("matrix.txt", "w");

    if(file == NULL) return errno;

    for(int i = 0; i < limit.row; i++){
        for(int j = 0; j < limit.column; j++){
            fprintf(file, "%d ", matrix[i][j]);
        }

        fprintf(file, "\n");
    }

    fclose(file);

    return 0;
}

int main(){
    int coords_length = 0, matrix[MAX_LOC][MAX_LOC];
    MATRIX_COORD matrix_limit, coords[MAX_LOC];

    printf("Informe o tamanho da matriz e quantos elementos serão zerados: \n");
    scanf("%d %d %d", &matrix_limit.row, &matrix_limit.column, &coords_length);

    read_zero_coords(coords, coords_length);

    fill_matrix(matrix, matrix_limit);
    zero_matrix(matrix, coords, coords_length);
    print_matrix(matrix, matrix_limit);

    return 0;
}
//
// Created by vinniciusj on 15/08/23.
//
#include <stdio.h>
#include <errno.h>

#define ARRAY_LENGTH 10
#define BIN_LENGTH 32


void fill_zeros(int * array, int quantity){
    for(int i = 0; i < quantity; i++){
        array[i] = 0;
    }
}

void toBinary(int number, int * binary){
    int index = BIN_LENGTH - 1;

    if (number == 0) binary[index] = 0;

    while (number > 0) {
        binary[index] = number % 2;
        number = number / 2;

        index--;
    }

    fill_zeros(binary, index + 1);
}

void print_binary(FILE * file, int * bin){
    for(int i = 0; i < BIN_LENGTH; i++){
        fprintf(file, "%d", bin[i]);
    }

    fprintf(file, "\n");
}

int print_in_file(int * array){
    FILE * file;
    int bin[BIN_LENGTH];

    file = fopen("output.txt", "w");

    if(file == NULL) return errno;

    for(int i = 0; i < ARRAY_LENGTH; array++, i++){
        toBinary(*array, bin);

        print_binary(file, bin);
    }

    fclose(file);

    return 0;
}

void read_array(int * array){
    for(int i = 0; i < ARRAY_LENGTH; i++, array++){
        scanf("%d", array);
    }
}

int main(){
    int array[ARRAY_LENGTH];

    printf("Informe os valores do vetor:\n");

    read_array(array);
    print_in_file(array);

    return 0;
}
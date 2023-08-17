//
// Created by vinniciusj on 14/08/23.
//
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<errno.h>

#define MAX_LOC 1000
#define ALPHA_LOC 26

int count_alpha_in_file(char * filename, int * alpha){
    FILE * file;
    char aux;

    file = fopen(filename, "r");

    if(file == NULL) return errno;

    while(fscanf(file, "%c", &aux) != EOF){
        if(isalpha(aux)){
            int index = ((int) tolower(aux)) - 97;

            alpha[index] = alpha[index] + 1;
        }
    }

    fclose(file);

    return 0;
}

void initialize_alpha_counter(int * alpha){
    for(int i = 0; i < ALPHA_LOC; i++, alpha++){
        *alpha = 0;
    }
}

void print_alpha_occurrences(int * alpha){
    for(int i = 0; i < ALPHA_LOC; i++, alpha++){
        printf("%c = %d\n", i + 97, *alpha);
    }
}

int main(){
    int alpha[ALPHA_LOC];
    char filename[MAX_LOC];

    printf("Informe o arquivo: ");
    scanf("%[^\n]%*c", filename);

    initialize_alpha_counter(alpha);
    count_alpha_in_file(filename, alpha);
    print_alpha_occurrences(alpha);

    return 0;
}
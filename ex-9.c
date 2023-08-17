//
// Created by vinniciusj on 14/08/23.
//
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<errno.h>

#define MAX_LOC 1000

void copy_file(FILE * input, FILE * output){
    char aux;

    while(fscanf(input, "%c", &aux) != EOF){
        fprintf(output, "%c", aux);
    }
}

int concat_files(char * st, char * nd){
    FILE * st_file, * nd_file, * output_file;

    st_file = fopen(st, "r");
    nd_file = fopen(nd, "r");
    output_file = fopen("output.txt", "a+");

    copy_file(st_file, output_file);
    copy_file(nd_file, output_file);

    fclose(st_file);
    fclose(nd_file);
    fclose(output_file);

    return 0;
}

int main(){
    char st[MAX_LOC], nd[MAX_LOC];

    printf("Informe o 1° arquivo: ");
    scanf("%[^\n]%*c", st);

    printf("Informe o 2° arquivo: ");
    scanf("%[^\n]%*c", nd);

    concat_files(st, nd);

    return 0;
}
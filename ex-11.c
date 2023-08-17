//
// Created by vinniciusj on 14/08/23.
//
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<errno.h>

#define MAX_LOC 100

int get_word_occurrences(char * filename, char * string, int * occurrences){
    FILE * file;
    char aux[MAX_LOC];

    file = fopen(filename, "r");

    if(file == NULL) return errno;

    while(fscanf(file, "%s", aux) != EOF){
        if(strcmp(string, aux) == 0){
            *occurrences = *occurrences + 1;
        }
    }

    fclose(file);

    return 0;
}

int main(){
    char filename[MAX_LOC], string[MAX_LOC];
    int occurrences = 0;

    printf("Informe o nome do arquivo: ");
    scanf("%[^\n]%*c", filename);

    printf("Procure por: ");
    scanf("%[^\n]%*c", string);


    get_word_occurrences(filename, string, &occurrences);

    printf("A palavra '%s' teve %d ocorrências no arquivo '%s'\n", string, occurrences, filename);

    return 0;
}
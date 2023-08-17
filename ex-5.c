//
// Created by vinniciusj on 14/08/23.
//
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<errno.h>

#define MAX_LOC 1000


int count_occurrences(char * string, char character){
    int counter = 0;

    for(int i = 0; i < strlen(string); i++){
        if(string[i] == character){
            counter++;
        }
    }

    return counter;
}

int count_occurrences_in_file(char * filename, char character, int * counter){
    FILE * file;
    char aux[MAX_LOC];

    file = fopen(filename, "r");

    if(file == NULL) return errno;

    while(fscanf(file, "%[^\n]%*c", aux) != EOF){
        *counter = *counter + count_occurrences(aux, character);
    }

    fclose(file);

    return 0;
}

int main(){
    int occurrences = 0;
    char character, filename[MAX_LOC];

    printf("Informe o nome do arquivo: ");
    scanf("%[^\n]%*c", filename);
    printf("Procurar por: ");
    scanf("%c", &character);

    count_occurrences_in_file(filename, character, &occurrences);

    printf("Foram encontrados %d ocorrências no arquivo %s", occurrences, filename);

    return 0;
}
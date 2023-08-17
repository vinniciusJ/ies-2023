//
// Created by vinniciusj on 14/08/23.
//
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<errno.h>

#define MAX_LOC 1000

int is_vowel(char character){
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

    for(int i = 0; i < 5; i++){
        if(tolower(character) == vowels[i]){
            return 1;
        }
    }

    return 0;
}

int count_vowels(char * string){
    int counter = 0;

    for(int i = 0; i < strlen(string); i++){
        if(is_vowel(string[i])){
            counter++;
        }
    }

    return counter;
}

int count_vowels_in_file(char * filename, int * counter){
    FILE * file;
    char aux[MAX_LOC];

    file = fopen(filename, "r");

    if(file == NULL) return errno;

    while(fscanf(file, "%[^\n]%*c", aux) != EOF){
        *counter = *counter + count_vowels(aux);
    }

    fclose(file);

    return 0;
}

int main(){
    int qtty = 0;
    char filename[MAX_LOC];

    printf("Infome o nome do arquivo: ");
    scanf("%[^\n]%*c", filename);

    count_vowels_in_file(filename, &qtty);

    printf("Existem %d vogais no arquivo %s\n", qtty, filename);

    return 0;
}
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

void count_letters(char * string, int * vowels, int * consonants){
    for(int i = 0; i < strlen(string); i++){
        if(isalpha(string[i])){
            if(is_vowel(string[i])){
                *vowels = *vowels + 1;
            }
            else{
                *consonants = *consonants + 1;
            }
        }
    }
}

int count_letters_in_file(char * filename, int * vowels, int * consonants){
    FILE * file;
    char aux[MAX_LOC];

    file = fopen(filename, "r");

    if(file == NULL) return errno;

    while(fscanf(file, "%[^\n]%*c", aux) != EOF){
        count_letters(aux, vowels, consonants);
    }

    fclose(file);

    return 0;
}

int main(){
    int vowels = 0, consonants = 0;
    char filename[MAX_LOC];

    printf("Infome o nome do arquivo: ");
    scanf("%[^\n]%*c", filename);

    count_letters_in_file(filename, &vowels, &consonants);

    printf("Existem %d vogais e %d no arquivo %s\n", vowels, consonants, filename);

    return 0;
}

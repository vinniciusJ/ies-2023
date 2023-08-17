//
// Created by vinniciusj on 14/08/23.
//
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<errno.h>

#define MAX_LOC 1000

int count_words(char * string){
    int count = 0, in_word = 0;

    while (*string) {
        if (isspace(*string)) {
            in_word = 0;
        } else {
            if (!in_word) {
                count++;
                in_word = 1;
            }
        }
        string++;
    }

    return count;
}

int get_lengths(char * filename, int * rows, int * words, int * chars){
    FILE * file;
    char aux[MAX_LOC];

    file = fopen(filename, "r");

    if(file == NULL) return errno;

    while(fscanf(file, "%[^\n]%*c", aux) != EOF){
        *rows = *rows + 1;
        *words = *words + count_words(aux);
        *chars = *chars + strlen(aux);
    }

    fclose(file);

    return 0;
}

int main(){
    char filename[MAX_LOC];
    int rows = 0, words = 0, chars = 0;

    printf("Informe o nome do arquivo: ");
    scanf("%[^\n]%*c", filename);

    get_lengths(filename, &rows, &words, &chars);

    printf("%d linhas, %d palavras, %d caracteres no arquivo '%s'", rows, words, chars, filename);

    return 0;
}
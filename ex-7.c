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

int replace_vowels(char * input){
    char aux;
    FILE *  input_file, * output_file;

    input_file = fopen(input, "r");
    output_file = fopen("output.txt", "w");

    if(input_file == NULL || output_file == NULL) return errno;

    while(fscanf(input_file, "%c", &aux) != EOF){
        fprintf(output_file, "%c", is_vowel(aux) ? '*' : aux);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}

int main(){
    char filename[MAX_LOC];

    printf("Informe o nome do arquivo: ");
    scanf("%[^\n]%*c", filename);

    replace_vowels(filename);

    return 0;
}
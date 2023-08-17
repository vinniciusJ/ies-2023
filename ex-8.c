//
// Created by vinniciusj on 14/08/23.
//
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<errno.h>

#define MAX_LOC 1000

int toggle_char(char character){
    if(isupper(character))
        return tolower(character);
    if(islower(character))
        return toupper(character);

    return character;
}

int toggle_file_characters(char * input, char * output){
    char character;
    FILE * input_file, * output_file;

    input_file = fopen(input, "r");
    output_file = fopen(output, "w");

    if(input_file == NULL || output_file == NULL) return errno;

    while(fscanf(input_file, "%c", &character) != EOF){
        fprintf(output_file, "%c", toggle_char(character));
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}

int main(){
    char input[MAX_LOC], output[MAX_LOC];

    printf("Informe o arquivo de entrada: ");
    scanf("%[^\n]%*c", input);

    printf("Informe o arquivo de saída: ");
    scanf("%[^\n]%*c", output);

    toggle_file_characters(input, output);

    return 0;
}
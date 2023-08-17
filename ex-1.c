// Permita que o usuario grave diversos caracteres nesse arquivo, até que o usuário entre com o caractere ‘0’
// Feito por Vinicius Jimenez
// 10/08/2023

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int write_file(char * filename){
    char aux;
    FILE * file;

    file = fopen(filename, "w");

    if(file == NULL) return errno;

    scanf("%c", &aux);

    while(aux != '0'){
        fprintf(file, "%c", aux);
        scanf("%c", &aux);
    }

    fclose(file);

    return 0;
}

int read_file(char * filename){
    char aux;
    FILE * file;

    file = fopen(filename, "r");

    if(file == NULL) return errno;

    while(fscanf(file, "%c", &aux) != EOF){
        printf("%c", aux);
    }

    fclose(file);

    return 0;
}

int main(){
    printf("Insira o texto a ser gravado no arquivo: \n");
    write_file("arq.txt");

    printf("\nO texto digitado foi: \n");
    read_file("arq.txt");

    return 0;
}

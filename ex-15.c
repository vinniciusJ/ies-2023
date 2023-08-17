//
// Created by vinniciusj on 14/08/23.
//
#include<stdio.h>
#include<string.h>
#include<errno.h>

#define MAX_LOC 100

typedef struct{
    char name[MAX_LOC];
    int birth_year;
} PERSON;

int calculate_age(int birth_year, int current_year){
    return current_year - birth_year;
};

char * get_age_status(int age){
    if(age < 18) return "Menor de idade";
    if(age > 18) return "Maior de idade";

    return "Entrando na maior idade";
}

int read_records(char * filename, PERSON * people, int * length){
    FILE * file;

    file = fopen(filename, "r");

    if(file == NULL) return errno;

    while(fscanf(file, "%s%*c %d %*c", people->name, &people->birth_year) != EOF){
        people++;
        *length = *length + 1;
    }

    fclose(file);

    return 0;
}

int generate_report(char * filename, int current_year, PERSON * people, int length){
    FILE * file;

    file = fopen(filename, "w");

    if(file == NULL) return errno;

    for(int i = 0; i < length; i++){
        int age = calculate_age(people[i].birth_year, current_year);

        fprintf(file, "%-25s %s\n", people[i].name, get_age_status(age));
    }

    fclose(file);

    return 0;
}

int main(){
    int length = 0, current_year = 0;
    char input[MAX_LOC], output[MAX_LOC];

    PERSON people[100];

    scanf("%d %s %s", &current_year, input, output);

    read_records(input, people, &length);
    generate_report(output, current_year, people, length);

    return 0;
}
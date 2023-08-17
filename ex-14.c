//
// Created by vinniciusj on 14/08/23.
//
#include<stdio.h>
#include<string.h>
#include<errno.h>

#define MAX_LOC 100

typedef struct {
    int year;
    int month;
    int day;
} DATE ;

typedef struct{
    char name[MAX_LOC];
    DATE birth_date;
} PERSON;

int calculate_age(DATE birth_date, DATE current_date){
    int age = current_date.year - birth_date.year;

    if(current_date.month < birth_date.month){
        age--;
    }

    if(current_date.month == birth_date.month){
        if(current_date.day < birth_date.day){
            age--;
        }
    }

    return age;
};

int read_records(char * filename, PERSON * people, int * length){
    FILE * file;

    file = fopen(filename, "r");

    if(file == NULL) return errno;

    while(fscanf(file, "%s%*c %d %d %d%*c", people->name, &people->birth_date.day, &people->birth_date.month, &people->birth_date.year) != EOF){
        people++;
        *length = *length + 1;
    }

    fclose(file);

    return 0;
}

int generate_report(DATE current_date, PERSON * people, int length){
    FILE * file;

    file = fopen("people.txt", "w");

    if(file == NULL) return errno;

    for(int i = 0; i < length; i++){
        fprintf(file, "%-25s %d anos\n", people[i].name, calculate_age(people[i].birth_date, current_date));
    }

    fclose(file);

    return 0;
}

int main(){
    int length = 0;
    char filename[MAX_LOC];
    PERSON people[100];
    DATE current_date;

    scanf("%s %d %d %d", filename, &current_date.day, &current_date.month, &current_date.year);

    read_records(filename, people, &length);
    generate_report(current_date, people, length);

    return 0;
}
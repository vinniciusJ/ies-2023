//
// Created by vinniciusj on 15/08/23.
//
#include <stdio.h>
#include <errno.h>

#define MAX_LOC 100
#define MAX_NAME 41
#define GRADES_LENGTH 3

typedef struct {
    char name[MAX_NAME];
    int grades[GRADES_LENGTH];
} STUDENT;

void swap(int * st_ptr, int * nd_ptr){
    int aux = *st_ptr;

    *st_ptr = *nd_ptr;
    *nd_ptr = aux;
}

int read_file(char * filename, STUDENT * students, int * length){
    FILE * file;

    file = fopen(filename, "r");


    if(file == NULL) return errno;


    while(fgets(students->name, 40, file) != NULL){
        fscanf(file, "%d %d %d%*c", &students->grades[0], &students->grades[1], &students->grades[2]);

        students++;
        *length = *length + 1;
    }

    fclose(file);

    return 0;
}

void sort(int * array, int length){
    for(int i = length - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(array[j] > array[j + 1]){
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void sort_students_grades(STUDENT * students, int length){
    for(int i = 0; i < length; i++, students++){
        sort(students->grades, GRADES_LENGTH);
    }
}

int print_result(char * filename, STUDENT * students, int length){
    FILE * file;

    file = fopen(filename, "w");

    if(file == NULL) return errno;

    for(int i = 0; i < length; i++, students++){
        fprintf(file, "Nome: %40s Notas: %d | %d | %d\n", students->name, students->grades[0], students->grades[1], students->grades[2]);
    }

    fclose(file);

    return 0;
}

int main(){
    int students_length = 0;
    char input[MAX_LOC], output[MAX_LOC];
    STUDENT students[MAX_LOC];

    printf("Informe os arquivos de entrada e saída, respectivamente: ");
    scanf("%s %s", input, output);

    read_file(input, students, &students_length);
    sort_students_grades(students, students_length);
    print_result(output, students, students_length);

    return 0;
}
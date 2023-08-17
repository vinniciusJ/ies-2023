//
// Created by vinniciusj on 15/08/23.
//
#include <stdio.h>
#include <errno.h>

#define MAX_LOC 100

typedef struct {
    char name[MAX_LOC];
    double grade;
} STUDENT;

int read_file(STUDENT  * students, int * length){
    FILE * file;

    file = fopen("students.txt", "r");

    if(file == NULL) return errno;

    while(fscanf(file, "%*[NOME: ]%s %*[NOTA:]%lf%*c", students->name, &students->grade) == 2){
        students++;
        *length = *length + 1;
    }

    fclose(file);

    return 0;
}

STUDENT get_highest_grade(STUDENT * students, int length){
    STUDENT * best_student = students;

    for(int i = 0; i < length; students++, i++){
        if(students->grade > best_student->grade){
            best_student = students;
        }
    }

    return *best_student;
}

int main(){
    int students_length = 0;
    STUDENT students[MAX_LOC], best_student;

    read_file(students, &students_length);
    best_student = get_highest_grade(students, students_length);

    printf("NOME: %s NOTA: %lf\n", best_student.name, best_student.grade);

    return 0;
}
//
// Created by vinniciusj on 14/08/23.
//
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<errno.h>

#define MAX_LOC 1000

typedef struct {
    char name[40];
    int population;
} CITY;

int get_cities(char * input, CITY * cities, int * length){
    CITY city;

    char aux[MAX_LOC];
    FILE * file;

    file = fopen(input, "r");

    if(file == NULL) return errno;

    for(; fscanf(file, "%[^\n]", aux) != EOF; cities++){
        strncpy(cities->name, aux, 40);
        sscanf(input + 40, "%d", &cities->population);
    }

    fclose(file);

    return 0;
}

CITY * get_most_populated_city(CITY * cities, int length){
    CITY * city = cities;

    for(int i = 0; i < length; i++, cities++){
        if(cities->population > city->population){
            city = cities;
        }
    }

    return city;
}

int print_most_populated_city(char * output, CITY city){
    FILE * file;

    file = fopen(output, "w");

    if(file == NULL) return errno;

    fprintf(file, "%s: %d habitantes\n", city.name, city.population);

    fclose(file);

    return 0;
}

int main(){
    int cities_length = 0;
    char input[MAX_LOC], output[MAX_LOC];
    CITY * most_populated_city, cities[100];

    printf("Informe o arquivo de entrada: ");
    scanf("%[^\n]%*c", input);

    printf("Informe o arquivo de saída: ");
    scanf("%[^\n]%*c", output);

    get_cities(input, cities, &cities_length);
    most_populated_city = get_most_populated_city(cities, cities_length);

    print_most_populated_city(output, *most_populated_city);

    return 0;
}
//
// Created by vinniciusj on 15/08/23.
//
#include<stdio.h>
#include <errno.h>

#define MAX_LOC 100

typedef struct {
    char name[MAX_LOC];
    double price;
} PRODUCT;

int read_invoice(PRODUCT * products, int * length){
    FILE * file;

    file = fopen("income.txt", "r");

    if(file == NULL) return errno;

    while(fscanf(file, "%s %lf", products->name, &products->price) == 2){
        products++;
        *length = *length + 1;
    }

    fclose(file);

    return 0;
}

double calculate_total(PRODUCT * products, int length){
    double total = 0.0;

    for(int i = 0; i < length; i++, products++){
        total += products->price;
    }

    return total;
}

int main(){
    int products_length = 0;
    PRODUCT products[MAX_LOC];

    read_invoice(products, &products_length);

    printf("O total da compra é: %lf\n", calculate_total(products, products_length));

    return 0;
}
//
// Created by vinniciusj on 14/08/23.
//
#include<stdio.h>
#include<string.h>
#include<errno.h>

#define MAX_LOC 1000

typedef struct {
    char name[MAX_LOC];
    char phone_number[MAX_LOC];
} CONTACT;

void read_contacts(CONTACT * contacts, int * length){
    CONTACT contact;

    *length = 0;
    scanf("%s%*c", contact.phone_number);

    while(strcmp(contact.phone_number, "0") != 0){
        scanf("%[^\n]%*c", contact.name);

        contacts[*length] = contact;
        *length = *length + 1;

        scanf("%s%*c", contact.phone_number);
    }
}

int print_contacts_in_file(CONTACT * contacts, int length){
    FILE * file;

    file = fopen("contacts.txt", "w");

    if(file == NULL) return errno;

    fprintf(file, "Nome                      Telefone\n");

    for(int i = 0; i < length; i++){
        fprintf(file, "%-25s %s\n", contacts[i].name, contacts[i].phone_number);
    }

    fclose(file);

    return 0;
}

int main(){
    int length = 0;
    CONTACT contacts[100];

    read_contacts(contacts, &length);
    print_contacts_in_file(contacts, length);

    return 0;
}
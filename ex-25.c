//
// Created by vinniciusj on 16/08/23.
//
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_ALOC 100
#define PHONE_LENGTH 11

typedef struct {
    int month;
    int day;
} BIRTH_DAY;

typedef struct {
    char name[MAX_ALOC];
    char phone_number[PHONE_LENGTH];
    BIRTH_DAY birth_day;
} CONTACT;

void choose_action(int action);
void add_contact();

CONTACT contacts[MAX_ALOC];
int contacts_length = 0;

void show_menu(){
    int option = 0;

    system("clear");
    printf("--------------- Lista telefonica -------------\n");
    printf("(0) Fechar agenda\n");
    printf("(1) Inserir contato\n");
    printf("(2) Remover contato\n");
    printf("(3) Pesquisar um contanto pelo nome\n");
    printf("(4) Listar todos os contatos\n");
    printf("(5) Imprimir os aniversariantes\n");
    printf("----------------------------------------------\n");
    printf("Escolha uma das opções acima: ");
    scanf("%d", &option);

    choose_action(option);
}

void wait_for_confirmation(){
    char confirm;

    printf("\nPressione 0 para continuar");
    scanf("%c", &confirm);

    while(confirm != '0'){
        scanf("%c", &confirm);
    }
}

void add_contact(){
    CONTACT contact;

    system("clear");
    printf("Nome: ");
    scanf("%*c%[^\n]", contact.name);
    printf("Telefone: ");
    scanf("%*c%[^\n]", contact.phone_number);
    printf("Aniversário (dd/mm): ");
    scanf("%d%*[/]%d%*c", &contact.birth_day.day, &contact.birth_day.month);

    contacts[contacts_length] = contact;
    contacts_length++;
}

void show_contacts(CONTACT * contacts_list, int length){
    system("clear");
    printf("     NOME                     TELEFONE       ANIVERSARIO\n");

    for(int i = 0; i < length; i++){
        printf("%-5d %-25s %-13s %02d/%02d\n", i + 1, contacts_list[i].name, contacts_list[i].phone_number, contacts_list[i].birth_day.day, contacts_list[i].birth_day.month);
    }
}

void list_all(){
    show_contacts(contacts, contacts_length);
    wait_for_confirmation();
}

void swap(CONTACT * st_ptr, CONTACT * nd_ptr){
    CONTACT aux = *st_ptr;

    *st_ptr = *nd_ptr;
    *nd_ptr = aux;
}

void remove_item(int index){
    for(int i = index; i < contacts_length; i++){
        swap(&contacts[i], &contacts[i + 1]);
    }

    contacts_length--;
}

void remove_contact(){
    int index = 0;

    system("clear");
    show_contacts(contacts, contacts_length);

    printf("\nInforme o indice do número a ser removido:  ");
    scanf("%d", &index);

    remove_item(index - 1);
}

void get_birthdays(CONTACT * birthdays, int * length){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("%d\n", tm.tm_mon);

    for(int i = 0; i < contacts_length; i++){
        if(contacts[i].birth_day.month == tm.tm_mon + 1){
            birthdays[*length] = contacts[i];

            *length = *length + 1;
        }
    }
}

void show_birthdays(){
    int birthdays_length = 0;
    CONTACT birthdays[MAX_ALOC];

    get_birthdays(birthdays, &birthdays_length);
    show_contacts(birthdays, birthdays_length);
    wait_for_confirmation();
}

char * to_lower(char * string){
    for(int i = 0; i < strlen(string) - 1; i++){
        string[i] = (char) tolower(string[i]);
    }

    return string;
}

CONTACT * find_by_name(char * name){
    for(int i = 0; i < contacts_length; i++){
        if(strcmp(to_lower(contacts[i].name), to_lower(name)) == 0){
            return &contacts[i];
        }
    }

    return NULL;
}

void find_contact(){
    char name[MAX_ALOC];
    CONTACT * found_contact;

    system("clear");
    printf("Informe o nome do contato: ");
    scanf("%*c%[^\n]%*c", name);

    found_contact = find_by_name(name);

    if(found_contact == NULL){
        printf("\nUsuário não encontrado");
        wait_for_confirmation();
        return;
    }

    show_contacts(found_contact, 1);
}

void choose_action(int action){
    switch (action) {
        case 0:
            return;
        case 1:
            add_contact();
            break;
        case 2:
            remove_contact();
            break;
        case 3:
            find_contact();
            break;
        case 4:
            list_all();
            break;
        case 5:
            show_birthdays();
            break;
        default:
            show_menu();
    }

    show_menu();
}

int main(){
    show_menu();

    return 0;
}



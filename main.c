#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node*next;
}struktura;

void push_last(struktura *head_node, int value) {
    if (head_node->next == NULL) {
        // First node with data
        head_node->next = malloc(sizeof(struktura));
        head_node->next->value = value;
        head_node->next->next = NULL;
    } else {
        // Second or later node with data
        struktura *current = head_node->next;
        while (current->next != NULL)
            current = current->next;

        current->next = malloc(sizeof(struktura));
        current->next->value = value;
        current->next->next = NULL;
    }
}
/*
void push_last(struktura *head_node, int rozmiar){ //ZAD1b.
    if (rozmiar <0) {
        printf("Mniejsze od 0");
        return -1;
    }
    if (rozmiar == 0) {
        if(head_node->next == NULL ){
            head_node->next = malloc(sizeof(struktura));
            head_node->next->value = NULL;
            head_node->next->next = NULL;
        } else {
            struktura *current = head_node->next;
            while (current->next != NULL)
                current = current->next;

                current->next = malloc(sizeof(struktura));
                current->next->value = NULL;
                current->next->next = NULL;
        }

    } else {
            for(int i=0; i<rozmiar; i++){
                if(head_node->next == NULL ){
                    head_node->next = malloc(sizeof(struktura));
                    head_node->next->value = NULL;
                    head_node->next->next = NULL;
                } else {
                    struktura *current = head_node->next;
                    while (current->next != NULL)
                    current = current->next;

                    current->next = malloc(sizeof(struktura));
                    current->next->value = NULL;
                    current->next->next = NULL;
                }
            }
            printf("Maksymalny rozmiar: %d\n", rozmiar);
        }
}*/

void push_number(struktura *head_node){      // ZAD 2b:
    if(head_node->next == NULL ){
        printf("nie jest dobrze");
    }
    struktura *current = head_node->next;
    int number;
    while (current->next != NULL) {
        printf("Podaj liczbe: ");
        scanf("%d", number);
        current->value = number;
        current = current->next;
    }
}

void printall(struktura *head_node){     //ZAD3b.
    struktura *current = head_node->next;
    while ( current != NULL){
        printf("%d", current->value);
        current = current->next;
    }

}

int pop_last(struktura *head_node, int number){ //ZAD4b.
    if (head_node->next == NULL) {
        return -1;
    }
    struktura *current = head_node->next;
    struktura *prev_current = head_node;
    while (current->next != NULL){
        prev_current = current;
        current = current->next;
    }
    int flaga = 0;
    if (current->value == number) {
        free(prev_current->next);
        prev_current->next = NULL;
        flaga++;
    }
    return flaga;
}

int licz_wyst(struktura *head_node, int i){ //ZAD5b.
    if(head_node->next == NULL ){
        return -1;
    }
    int licz = 0;
    struktura *current = head_node->next;
    while ( current != NULL){
        if (current->value == i)
            licz++;
        current = current->next;
    }
    return licz;
}

int main (){
    printf("Wybierz funkcje, ktora chcesz uzyc:\n\t1. Stworzenie listy\n\t2. Dodanie wartosci do listy\n\t3. Wyswietl liste\n\t4. Usun ostatnia wartosc\n\t5. Liczba wystapien wystepowania liczby\n\t6. EXIT\n");
    int opcja, rozmiar;

//    while (opcja != 6) {
//    scanf("%d", opcja);

//    switch (opcja) {
//case 1:

    //printf("Podaj rozmiar listy: ");
    //scanf("%d", rozmiar);

    struktura *struk = NULL;
    struk = malloc(sizeof(struktura));
    if (struk == NULL)
        return 1;
    //struk->next = NULL;
    rozmiar = 5;

    push_last(struk, rozmiar);
    //break;
//case 2:
    // struktura *struk = NULL;
    // struk = malloc(sizeof(struktura));
    if (struk == NULL)
        return 1;
    push_number(struk);
//        break;
//case 3:
    //  struktura *struk = NULL;
    //  struk = malloc(sizeof(struktura));
    if (struk == NULL)
        return 1;
    printall(struk);
//        break;
//case 4:
    //   struktura *struk = NULL;
    //    struk = malloc(sizeof(struktura));
    if (struk == NULL)
        return 1;

    printf("Podaj wartosc do usuniecia: ");
    int number;
    scanf("%d", number);
    pop_last(struk, number);
//        break;
//case 5:
    //    struktura *struk = NULL;
    //   struk = malloc(sizeof(struktura));
    if (struk == NULL)
        return 1;

    printf("Podaj wartosc do zliczenia: ");
    int i;
    scanf("%d", i);
    licz_wyst(struk, i);
//        break;
//case 6:
    return 0;
}

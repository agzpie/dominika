#include <stdio.h>
#include <stdlib.h>

int flaga = 0;

int stack_size = 0;
int max_stack_size = 0;

typedef struct node{
    int value;
    struct node*next;
}struktura;

int isfull(struktura *head_node) {
    if (stack_size == max_stack_size)
        return 1;
    else
        return 0;
}

void push(struktura *head_node, int value){ // ZAD 2b.
    if (stack_size == max_stack_size) {
        printf("Max stack size reached. No action.");
        return;
    }

    // Increase stack node count
    stack_size++;

    // Create new node
    struktura *node = NULL;
    node = malloc(sizeof(struktura));
    node->next = head_node->next;
    node->value = value;

    head_node->next = node;
}

void printall(struktura *head_node) {     //ZAD3b.
    struktura *current = head_node->next;

    while ( current != NULL){
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

int top(struktura *head_node) {
    //if (head_node->next == NULL)
    //    return -8;

    return head_node->next->value;
}

int pop(struktura *head_node) {
    struktura *popped = head_node->next;
    head_node->next = head_node->next->next;
    int value = popped->value;
    free(popped);

    return value;
}

int pobieranie(struktura *head_node, int number) { //ZAD4b.
    if (top(head_node) == number) {
        pop(head_node);

        return 1;
    }

    return 0;
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

struktura* createstack(int max) { //zad1b tworzenie pustego stosu
    max_stack_size = max;

    struktura *struk = NULL;
    struk = malloc(sizeof(struktura));

    struk->next = NULL;

    return struk;
}


int main () {
    printf("\t1. Stworzenie listy\n\t2. Dodanie wartosci do listy\n\t3. Wyswietl liste\n\t4. Usun ostatnia wartosc\n\t5. Liczba wystapien wystepowania liczby\n\t6. EXIT\n");
    int opcja, rozmiar, wartosc;

    rozmiar = 5;
    struktura *struk = createstack(rozmiar);
    if (struk == NULL)
        return 1;

    printf("max = %d\n", max_stack_size);
    printf("stack_size = %d\n", stack_size);
    printf("loop\n");
    for (int i = 1; i <= rozmiar; i++) {
        push(struk, i);
    }

    printf("stack_size = %d\n", stack_size);
    printall(struk);
    printf("pop = %d\n", pop(struk));
    printall(struk);
    printf("top = %d\n", top(struk));
    printall(struk);
    printf("pobieranie 4 = %d\n", pobieranie(struk, 4));
    printall(struk);
    printf("pobieranie 2 = %d\n", pobieranie(struk, 2));
    printall(struk);
    printf("licz_wyst 2 = %d\n", licz_wyst(struk, 2));
    printall(struk);
    printf("licz_wyst 6 = %d\n", licz_wyst(struk, 6));
    printall(struk);


    /*
    printf("Podaj rozmiar stosu: ");
    scanf("%d", &rozmiar);

    struktura *struk = createstack(rozmiar);
    if (struk == NULL)
        return 1;

    for (int i = 0; i < rozmiar; i++) {
        push(struk, rozmiar);
    }

    printf("Rozmiar listy to: %d\n", rozmiar);
    push(struk, rozmiar);
    printall(struk, rozmiar);
    printf("Podaj wartosc do usuniecia: ");
    int number;
    scanf("%d", &number);
    pop(struk, number, rozmiar);
    printall(struk, rozmiar);
    printf("Podaj wartosc do zliczenia: ");
    int i;
    scanf("%d", &i);
    licz_wyst(struk, i);*/

    return 0;
}
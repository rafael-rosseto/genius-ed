#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

typedef struct NO_FILA {
    int color;                      //linkar as cores com os números
    struct NO_FILA *next;
} NO_FILA;

typedef struct FILA {
    NO_FILA *head;
    NO_FILA *tail;
    int level;                      //usado para comparar o input do usuário com as cores na sequência
} FILA;

// functions

int randLuz()
{
    return (rand() % 4);
}

void iniciaFila(FILA *q) {
    q->head = NULL;
    q->tail = NULL;
}

void pushFila(int data, FILA *q) {
    NO_FILA *ptr = (NO_FILA*) malloc(sizeof(NO_FILA));

    if(ptr == NULL) {
        printf("Erro de alocacao!\n");
        return;
    } else {
        ptr->color = data;
        ptr->next = NULL;
        if(q->head == NULL) {
            q->head = ptr;
        } else {
            q->tail->next = ptr;
        }
        q->tail = ptr;
        q->level += 1;
    }
}

/*
 * Pop function unecessary

void popFila(FILA *q) {
    NO_FILA *ptr = q->head;
    int data;
    if(ptr != NULL) {
        q->head = ptr->next;
        ptr->next = NULL;
        data = ptr->color;
        free(ptr);
        if(q->head == NULL) {
            q->tail = NULL;
        }
        printf("\n%d foi retirado", data);
    } else {
        printf("\nA fila esta vazia!");
        return 0;
    }
}
*/

void resetFila(FILA *q) {
    NO_FILA *ptr = q->head;

    if(ptr != NULL) {
        while(ptr != NULL) {
            q->head = ptr->next;
            ptr->next = NULL;
            ptr = q->head;
        }
        free(ptr);
        printf("\nfila foi esvaziada!\n");
    }
    else {
        printf("\nfila ja estava vazia\n");
    }
    q->head = NULL;
    q->tail = NULL;
}

void printFila(FILA *q) {
    NO_FILA *ptr = q->head;

    if(ptr != NULL) {
        while(ptr != NULL) {
            printf("%d ", ptr->color);
            ptr = ptr->next;
        }
    } else {
        printf("\nA fila esta vazia!\n");
    }
}

bool verificaFila(FILA *q) {
    int cont, data;
    NO_FILA *ptr = q->head;

    for(cont=0; cont < q->level; cont++) {
        printf("\n%do: ", cont+1);
        scanf("%d", &data);
        if(data != ptr->color) {
            return false;
        }
        ptr = ptr->next;
    }
    return true;
}

/*
 * Legacy Code

typedef enum
{
    FALSE,
    TRUE
} bolean;

typedef struct no *No;

struct no
{
    short luz;
    No prox, ant;
} Luzes;

No criarNo()
{
    No p = (No)malloc(sizeof(Luzes));
    p->prox = NULL;
    p->ant = NULL;
    return p;
}

void inserirLuz(short luz, No *ult)
{
    No p, ultimo = *ult;
    p = criarNo();
    p->luz = luz;
    *ult = p;
    ultimo->prox = p;
    p->ant = ultimo;
}

void imprimirLista(No *ini)
{
    No p;
    for (p = *ini; p != NULL; p = p->prox)
        printf("%d \n", p->luz);
}

void tamanhoLista(No *ini)
{
    No p = *ini;
    int i = 0;
    for (; p != NULL; p = p->prox)
        i++;
    printf("Possui %d luzes", i);
}

void limparLista(No *ini, No *ult)
{
    No p = (*ini)->prox;
    for (; (p->prox = NULL); p = p->prox)
        free(p->ant);
    free(p->ant);
    free(p);
    *ini = NULL;
    *ult = NULL;
}

bolean compararTamanho(No *ini1, No *ini2)
{
    No p1 = *ini1, p2 = *ini2;
    while (p1 != NULL && p2 != NULL)
    {
        p1 = p1->prox;
        p2 = p2->prox;
    }
    if (p1 != NULL)
        return TRUE;
    else
        return FALSE;
}

bolean compararListas(No *ini1, No *ini2)
{
    No p1 = *ini1, p2 = *ini2;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->luz != p2->luz)
            return FALSE;
        p1 = p1->prox;
        p2 = p2->prox;
    }
    if (p1 == NULL && p2 == NULL)
        return TRUE;
    else
        return FALSE;
}

bolean patternMatching(No *ini1, No *ini2)
{
    No p1 = *ini1, p2 = *ini2;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->luz == p2->luz)
        {
            p2 = p2->prox;
        }
        else if (p2 != *ini2)
        {
            p2 = *ini2;
        }
        p1 = p1->prox;
    }
    if (p2 == NULL)
        return TRUE;
    else
        return FALSE;
}

* End Legacy Code
*/

#endif // ESTRUTURAS_H

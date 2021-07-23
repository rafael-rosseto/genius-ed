#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

short randLuz()
{
    return (rand() % 4);
}

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

#endif // ESTRUTURAS_H

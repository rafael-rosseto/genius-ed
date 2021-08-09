#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include <QDebug>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int level = 1;
int cont_glob = 0;

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
        qInfo("Erro de alocacao!\n");
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
        //level += 1;
    }
}

/*
// Função para Pop da pilha

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
        qInfo("\nfila foi esvaziada!\n");
    }
    else {
        qInfo("\nfila ja estava vazia\n");
    }
    q->head = NULL;
    q->tail = NULL;
}

void printFila(FILA *q) {
    NO_FILA *ptr = q->head;

    if(ptr != NULL) {
        while(ptr != NULL) {
            qInfo("%d ", ptr->color);
            ptr = ptr->next;
        }
    } else {
        qInfo("\nA fila esta vazia!\n");
    }
}

bool verificaFila(FILA *input, FILA *output) {
    int cont;
    NO_FILA *ptr_in = input->head;
    NO_FILA *ptr_out = output->head;

    for(cont=1; cont <= cont_glob; cont++) {
        if(ptr_in->color != ptr_out->color) {
            return false;
        }
        ptr_in = ptr_in->next;
        ptr_out = ptr_out->next;
    }
    return true;
}

#endif // ESTRUTURAS_H

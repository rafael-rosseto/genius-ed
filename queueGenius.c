// genius

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

void main(){
    srand(time(NULL));

    FILA *sequencia = (FILA*) malloc(sizeof(FILA));
    sequencia->level = 0;
    iniciaFila(sequencia);

    short continuar = 1;
    bool test;

    if(sequencia == NULL) {
        printf("Erro de alocacao!\n");
        exit(-1);
    } else {
        do {
            pushFila(rand() % 4, sequencia);
            printFila(sequencia);
            test = verificaFila(sequencia);
            if(test) {
                continuar = 1;
            } else {
                printf("\n\nGame over!\n\n");           //substituir por uma interface melhor
                resetFila(sequencia);
                sequencia->level = 0;
                printf("\nContinuar?\n0-nao\n1-sim\n"); //substituir por uma interface melhor
                scanf("%d", &continuar);                //substituir por uma interface melhor
            }
        } while(continuar);

    }
    return;
}

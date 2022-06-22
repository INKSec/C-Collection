/******************************************************************
* Projekt: Algorithmen und Datenstrukturen
* Dateiname: main.c
* Beschreibung: Uebung 4 Aufgabe 2
* Autor: Michael Burkhardt 
* Matr.-Nr.: 937645

* Erstellt: 09.06.2021
******************************************************************/
// Rumpfskript zu Übungsblatt 4, Aufgabe 2
// Anlegen, Traversieren und Auswerten eines Ausdrucksbaums
// Autor: H. Schramm
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char type;          /* Operatorzeichen oder '0' fuer Zahlenknoten */
    double number;      /* Zahl fuer Zahlenknoten oder 0.0 */
    struct node *pleft, *pright;/* Zeiger auf linken und rechten Teilbaum */
}
TNode;
TNode *compose_tree(char type, double value, TNode *pleft, TNode *pright);
void ausgabePreorder(TNode *node);
void ausgabePostorder(TNode *node);
void ausgabeInorder(TNode *node);
float auswerten(TNode *node);

int main() {
    TNode *proot, *left, *right;
    left = compose_tree('0', 3.0, NULL, NULL);
    right = compose_tree('0', 2.0, NULL, NULL);
    proot = compose_tree('*', 0.0, left, right);
    left = compose_tree('0', 8.0, NULL, NULL);
    right = compose_tree('0', 4.0, NULL, NULL);
    right = compose_tree('/', 0.0, left, right);
    proot = compose_tree('+', 0.0, proot, right);

    ausgabePreorder(proot);
    printf("\n");
    ausgabeInorder(proot);
    printf("\n");
    ausgabePostorder(proot);
    printf("\n");
    printf("Auswertung des Baumes ergibt: %.2f\n", auswerten(proot));

    return 0;
}

TNode *compose_tree(char type, double value, TNode *pleft, TNode *pright) {
    TNode *proot; /* Zeiger auf neues Element */

    proot = (TNode *)malloc(sizeof(TNode));
    if (proot != NULL) {
        proot->type = type;
        proot->number = value;
        proot->pleft = pleft;
        proot->pright = pright;
    }
    return proot;
}

void ausgabePreorder(TNode *node) {
    if (node != NULL) {
        if (node->type != '0') {
            printf("%c\n", node->type);
        } else {
            printf("%.2f\n", node->number);
        }

        if (node->pleft != NULL) {
            ausgabePreorder(node->pleft);
        }
        if (node->pright != NULL) {
            ausgabePreorder(node->pright);
        }
    }
    return;
}

void ausgabeInorder(TNode *node) {
    if (node != NULL) {
        if (node->pleft != NULL) {
            ausgabeInorder(node->pleft);
        }

        if (node->type != '0') {
            printf("%c\n", node->type);
        } else {
            printf("%.2f\n", node->number);
        }
        if (node->pright != NULL) {
            ausgabeInorder(node->pright);
        }
    }
    return;
}

void ausgabePostorder(TNode *node) {
    if (node != NULL) {
        if (node->pleft != NULL) {
            ausgabePostorder(node->pleft);
        }
        if (node->pright != NULL) {
            ausgabePostorder(node->pright);
        }
        if (node->type != '0') {
            printf("%c\n", node->type);
        } else {
            printf("%.2f\n", node->number);
        }
    }
    return;
}

float auswerten(TNode *node) {
    if (node != NULL) {
        if (node->type == '+') {
            return auswerten(node->pleft) + auswerten(node->pright);
        } else if (node->type == '-') {
            return auswerten(node->pleft) - auswerten(node->pright);
        } else if (node->type == '*') {
            return auswerten(node->pleft) * auswerten(node->pright);
        } else if (node->type == '/') {
            return auswerten(node->pleft) / auswerten(node->pright);
        } else {
            return node->number;
        }
    } else {
        printf("Invalid tree");
        exit(0);
    }
}

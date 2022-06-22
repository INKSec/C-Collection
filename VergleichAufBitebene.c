#include <stdio.h>

int main(void) {
    /*
    Laborzettel 4 Aufgabe 2

    Autor: Michael Burkhardt, Matrikelnummer 937645, Gruppe 2

    Datum 27.01.2021

    Version: 1.0

    */

    int a;
    printf("Bitte geben Sie eine 32-Bit Integerzahl ein:\n");
    scanf("%d", &a);

    unsigned int maske;
    maske = 1<<31;
    int i = 1;

    // Führt die Schleife aus bis die Variable maske 1 wird 
    do { 
        //Um eine Zahl auszugeben wird auf Bitebene verglichen
        if (a &  maske != 0) {
                printf("1");
                /*
                Um Leerzeichen einzubauen wird geprüft ob 
                Zaehler durch vier teilbar und dann erhöht
                */
               if (i%4) {
               i++;
               } else {
               printf(" ");
               i++;
               }
        } else {
            printf("0");
               if (i%4) {
               i++;
               } else {
               printf(" ");
               i++;
               }
           }
        //Anpassen der Maske um jedes Bit zu überprüfen				
        maske = maske>>1;	
    } while (maske >= 1);

    return 0;
	
	
	
}
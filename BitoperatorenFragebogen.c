#include <stdio.h>

int main(void) {
    /*
    Laborzettel 4 Aufgabe 4

    Autor: Michael Burkhardt, Matrikelnummer 937645, Gruppe 2

    Datum 27.01.2021

    Version: 1.0

    */
    // Deklaration/Definition der Variablen
    int eingabe_1;
    int eingabe_2;
    int richtig_zaehler = 0;

    int eingabe_aufgabe_1, eingabe_aufgabe_2, eingabe_aufgabe_3;
    int eingabe_aufgabe_4, eingabe_aufgabe_5, eingabe_aufgabe_6;

    printf("Geben Sie zwei Ganzzahlen >= 0 ");
    printf("(durch Leerzeichen getrennt) ein:\n");
    scanf("%d %d", &eingabe_1, &eingabe_2);

    // Frage 1
    printf("Wieviel ist %d & %d?\n", eingabe_1, eingabe_2);
    scanf("%d", &eingabe_aufgabe_1);

    /*
    Vergleich verschiedener Nutzereingaben
    Eingabewerte: eingabe_1, eingabe_2, eingabe_aufgabe_1
    Ausgabewerte: richtig_zaehler++, falsch_zaehler++
    Michael Burkhardt
    Wird bei jeder Frage wiederverwertet, nur die Operanten wechseln
    */
    if ((eingabe_1 & eingabe_2) == eingabe_aufgabe_1) {
        printf("Richtig!\n\n");
        richtig_zaehler++;

    } else {
        printf("Falsch! (Richtig waere %d & %d =", eingabe_1, eingabe_2);
        printf(" %d)\n\n", eingabe_1 & eingabe_2);
    }

    // Frage 2
    printf("Wieviel ist %d | %d?\n", eingabe_1, eingabe_2);
    scanf("%d", &eingabe_aufgabe_2);

    if ((eingabe_1 | eingabe_2) == eingabe_aufgabe_2) {
        printf("Richtig!\n\n");
        richtig_zaehler++;

    } else {
        printf("Falsch! (Richtig waere %d | %d =", eingabe_1, eingabe_2);
        printf(" %d)\n\n", eingabe_1 | eingabe_2);
    }

    // Frage 3
    printf("Wieviel ist %d ^ %d?\n", eingabe_1, eingabe_2);
    scanf("%d", &eingabe_aufgabe_3);

    if ((eingabe_1 ^ eingabe_2) == eingabe_aufgabe_3) {
        printf("Richtig!\n\n");
        richtig_zaehler++;

    } else {
        printf("Falsch! (Richtig waere %d ^ %d =", eingabe_1, eingabe_2);
        printf(" %d)\n\n", eingabe_1 ^ eingabe_2);
    }

    // Frage 4
    printf("Wieviel ist ~%d?\n", eingabe_1);
    scanf("%d", &eingabe_aufgabe_4);

    if ((~eingabe_1) == eingabe_aufgabe_4) {
        printf("Richtig!\n\n");
        richtig_zaehler++;

    } else {
        printf("Falsch! (Richtig waere ~%d = %d)\n\n", eingabe_1, ~eingabe_1);
    }

    // Frage 5
    printf("Wieviel ist %d >> %d?\n", eingabe_1, eingabe_2);
    scanf("%d", &eingabe_aufgabe_5);

    if ((eingabe_1 >> eingabe_2) == eingabe_aufgabe_5) {
        printf("Richtig!\n\n");
        richtig_zaehler++;

    } else {
        printf("Falsch! (Richtig waere %d >> %d =", eingabe_1, eingabe_2);
        printf(" %d)\n\n", eingabe_1 >> eingabe_2);
    }

    // Frage 6
    printf("Wieviel ist %d << %d?\n", eingabe_1, eingabe_2);
    scanf("%d", &eingabe_aufgabe_6);

    if ((eingabe_1 << eingabe_2) == eingabe_aufgabe_6) {
        printf("Richtig!\n\n");
        richtig_zaehler++;

    } else {
        printf("Falsch! (Richtig waere %d << %d =", eingabe_1, eingabe_2);
        printf(" %d)\n\n", eingabe_1 << eingabe_2);
    }

    printf("Ergebnis der Bit-Operator-Uebungen:\n\n");
    printf("Sie haben %d Aufgaben richtig geloest!", richtig_zaehler);

    return 0;
}
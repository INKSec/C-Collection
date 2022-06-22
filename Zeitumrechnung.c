#include <stdio.h>
#include <time.h>
int main(void){

/*
    Laborzettel 3 Aufgabe 3

    Autor: Michael Burkhardt, Matrikelnummer 937645, Gruppe 2

    Datum 02.01.2021

    Version: 1.0

*/

    // initialisierung der Variablen
    long zeitInSekunden = time(0); //Zeit in Sekunden seit 01.01.1970
    long Minuten, Stunden, Tage, Wochen, Jahre;

    // Rechenoperationen fuer die Zeitangabe
    Minuten = zeitInSekunden / 60;
    Stunden = Minuten / 60;
    Tage = Stunden / 24;
    Wochen = Tage / 7;
    Jahre = Wochen / 52;

    // Ausgabe der Errechneten Werte
    printf("Seit dem 01.01.1970 sind vergangen:\n");
    printf("%ld Sekunden\n", zeitInSekunden);
    printf("Das sind        %ld Minuten\n", Minuten);
    printf("oder            %ld Stunden\n", Stunden);
    printf("oder            %ld Tage\n", Tage);
    printf("oder            %ld Wochen\n", Wochen);
    printf("oder            %ld Jahre\n\n", Jahre);

    //Initialisieren der Restvariablen
    float Sekundenseit1970, MinutenSeit1970, RestMinutenSeit1970;
    float RestStundenSeit1970, StundenSeit1970, TageSeit1970, RestTage1970, JahreSeit1970, restJahreSeit1970;

    // Rechenoperationen fuer den zweiten Aufgabenteil
    JahreSeit1970 = zeitInSekunden /  31536000.;
    restJahreSeit1970 = (int)zeitInSekunden % 31536000;

    // Tage
    TageSeit1970 = (int)restJahreSeit1970 / 86400; 
    RestTage1970 = (int)restJahreSeit1970 % 86400;

    // Stunden
    StundenSeit1970 = (int)RestTage1970 / 3600;
    RestStundenSeit1970 = (int)RestTage1970 % 3600;

    // Minuten
    MinutenSeit1970 = (int)RestStundenSeit1970 / 60;    
    RestMinutenSeit1970 = (int)RestStundenSeit1970 % 60;

    // Sekunden
    Sekundenseit1970 = (int)RestMinutenSeit1970 % 60;

    printf("-------------\n");

    //Ausgabe der Vergangenen Zeit kombiniert - Teilung zur besseren Uebersicht
    printf("Seit dem 01.01.1970 sind vergangen:\n");

    printf("%.0f Jahre, %.0f Tage, %.0f Stunden, %.0f Minuten, ", JahreSeit1970, TageSeit1970, StundenSeit1970, MinutenSeit1970);
    printf("%f Sekunden", Sekundenseit1970);

    return 0;
}
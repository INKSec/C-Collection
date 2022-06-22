/******************************************************************
* Projekt: Algorithmen und Datenstrukturen
* Dateiname: main.c
* Beschreibung: ???
* Autor: Michael Burkhardt
* Matr.-Nr.: 911911
* Erstellt: 31.05.2021
******************************************************************/

/*********** Hinweis ***********/
/*
Einzelne Tests in CodeFreak können unerwartet fehlschlagen.
Das kann auch daran liegen, dass die Aufgabenstellung im Detail
unterschiedlich interpretiert werden kann. Beispielsweise setzen die
Tests voraus, dass bei einer leeren Liste immer ein Element an Position 1
eingefügt werden kann.

Funktioniert das Programm in Ihren Augen korrekt, fragen Sie gern nach,
warum ein bestimmter Test fehlschlägt.
*/


#include <stdio.h>
#include <stdlib.h>

// Hier Konstanten und Statuscodes definieren
#define NOT_IMPLEMENTED_ERROR -1000
#define NICHT_GENUG_SPEICHER -100
#define UNGUELTIGE_POSITION -10
#define KEINE_ELEMENTE_VORHANDEN -1
#define ELEMENT_NICHT_VORHANDEN -2

// Hier Struktur und globale Variablen definieren
typedef struct listnode {
	int data;
	struct listnode *next;
}Listnode;

Listnode *pstart=NULL, *p;




// Vorgegebene Enumeration als Hilfestellung
enum DIRECTION { FORWARD, REVERSE } direction;


/* Vorgegebene Unterprogramme zur Verwaltung der verketteten Liste */
/* Die folgenden 6 Funktionen werden von CodeFreak erwartet.       */
/* Fehler sollten durch die Rückgabe eines negativen Statuscodes   */
/* kenntlich gemacht werden. */
int put_entry(int position, int aktdata);  /* Eintrag einfuegen */
int del_entry(int position);               /* Eintrag Loeschen  */
int find_entry(int value);                 /* Eintrag suchen    */
void del_list(void);                       /* Liste loeschen    */
int get_anzentries(void);                  /* Anzahl ermitteln  */
int printall(enum DIRECTION direction);    /* Liste ausgeben    */


int main(void)
{
    p=(Listnode *)malloc(sizeof(Listnode));
    p->data = 15;
    p->next = NULL;
    pstart = p;
    p=(Listnode *)malloc(sizeof(Listnode));
    p->data = 27;
    p->next = NULL;
    pstart->next = p;
    p=(Listnode *)malloc(sizeof(Listnode));
    p->data = 99;
    p->next = NULL;
    pstart->next->next = p;
    put_entry(1,2);
    put_entry(1,2);
    put_entry(4,2);
    printall(FORWARD);




    del_entry(88);
    printf("Löschen\n");
    printall(FORWARD);
    
    
    return 0;
}

/* Unterprogramm zum Einfuegen eines Nutzdatenelements
*  Parameter: position = Einfuegepos.; 0 = vor pstart
*             aktdata  = einzufuegende Zahl
*/
int put_entry(int position, int aktdata) /* Einfuegen */
{
    Listnode *ptr, *temp;
    int i;

    temp = (Listnode *)malloc(sizeof(Listnode));
    if(temp==NULL)
    {
        return NICHT_GENUG_SPEICHER; 
    }
    temp->next=NULL;
    temp->data = aktdata;
    if(position==0)
    {
        temp->next = pstart;
        pstart = temp;
    }
    else 
    {
        for(i=0, ptr = pstart; i<position-1; i++) 
        {
            ptr=ptr->next;
            if(ptr==NULL)
            {
                return UNGUELTIGE_POSITION;
            }
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
}


/* Unterprogramm zu Ausgabe aller Listenelemente
*  Parameter: direction  = FORWARD	vorwaerts
*                        = REVERSE	rueckwaerts
*  Return:    0          = alles OK
*         negative Werte = Fehler
*/
int printall(enum DIRECTION direction)
{
    Listnode *ptr;
    if(direction == FORWARD)
    {
        ptr = pstart;
        printf("Die Daten der Elemente sind: \n");
        while(ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
    else if(direction == REVERSE)
    {
         // FEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEHLT   
    }	
}

/* Unterprogramm zum Loeschen der gesamten Liste
*  Parameter: keine
*  Return:    0         = Loeschen OK
*         negative Werte = Fehler
*/
void del_list(void)  // TODO hat gar keinen Rückgabewert 
{
    Listnode *zeiger, *temp;
    if(pstart != NULL)
    {
        zeiger = pstart->next;
        pstart->next = NULL;
        while(zeiger != NULL)
        {
            temp = zeiger->next;
            free(zeiger);
            zeiger = temp;
        }
    }
    free(pstart);

}


/* Unterprogramm zum Loeschen eines Nutzdatenelements
*  Parameter: position   = Loeschpos.;
*  Return:    0          = Loeschen OK
*         negative Werte = Fehler
*/
int del_entry(int position) /* Loeschen (delete) */
{
    int i;
    Listnode *temp, *ptr;
    if(pstart == NULL)
    {
        return KEINE_ELEMENTE_VORHANDEN;
    }

	if(position == 0)
	{
	    ptr = pstart;
	    pstart = pstart->next;
	    free(ptr);
	}
	else 
	{
	    ptr = pstart;
	    for(i=0;i<position;i++)
	    {
	        temp=ptr;
	        ptr=ptr->next;
	        if(ptr == NULL)
	        {
	            printf("Nicht gefunden");
	            return ELEMENT_NICHT_VORHANDEN;
	        }
	    }
	    temp->next = ptr->next;
	    free(ptr);
	}

    return 0;
}

/* Unterprogramm zur Ermittlung der Elementanzahl
*  Parameter: keine
*  Return:    aktuelle Anzahl der Element
*/
int get_anzentries(void)      /* Anzahl ermitteln  */
{
    int zaehler = 0;
    Listnode *ptr = pstart;
    if(pstart == NULL)
    {
        return KEINE_ELEMENTE_VORHANDEN;
    }
    while(ptr != NULL)
    {
        ptr = ptr->next;
        zaehler++;
    }
    return zaehler;

}

/* Unterprogramm zum Suchen eines Elementes
*  Parameter: value      = Zahl, nach der gesucht wird
*  Return:    0          = nicht gefunden
*         negative Werte = Fehler
*/
int find_entry(int value)
{
    Listnode *ptr = pstart;
    if(ptr == NULL)
    {
        return KEINE_ELEMENTE_VORHANDEN;
    }

    while(ptr != NULL)
    {
        if(ptr->data == value)
        {
            return ptr;
        }
        else
        {
            ptr = ptr->next;
        }

    }
    return 0;
}
	



    

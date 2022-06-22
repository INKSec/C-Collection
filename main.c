
/******************************************************************
* Projekt: Algorithmen und Datenstrukturen
* Dateiname: main.c
* Beschreibung: Das Programm kann eine Liste verwalten. Leider 
* war ich nicht in der Lage einen Test in CodeFreak zu bestehen.
* Autor: Michael Burkhardt
* Matr.-Nr.: 937645
* Erstellt: 31.05.2021
******************************************************************/

/*********** Hinweis ***********/
/*
Einzelne Tests in CodeFreak koennen unerwartet fehlschlagen.
Das kann auch daran liegen, dass die Aufgabenstellung im Detail
unterschiedlich interpretiert werden kann. Beispielsweise setzen die
Tests voraus, dass bei einer leeren Liste immer ein Element an Position 1
eingefuegt werden kann.

Funktioniert das Programm in Ihren Augen korrekt, fragen Sie gern nach,
warum ein bestimmter Test fehlschlaegt.
*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// Hier Konstanten und Statuscodes definieren
#define NOT_IMPLEMENTED_ERROR -1000
#define NICHT_GENUG_SPEICHER -100
#define UNGUELTIGE_POSITION -10
#define KEINE_ELEMENTE_VORHANDEN -1
#define ELEMENT_NICHT_VORHANDEN -2
#define UEBERTREIB_NICHT -42


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
/* Fehler sollten durch die Rueckgabe eines negativen Statuscodes   */
/* kenntlich gemacht werden. */
int put_entry(int position, int aktdata);  /* Eintrag einfuegen */
int del_entry(int position);               /* Eintrag Loeschen  */
int find_entry(int value);                 /* Eintrag suchen    */
void del_list(void);                       /* Liste loeschen    */
int get_anzentries(void);                  /* Anzahl ermitteln  */
int printall(enum DIRECTION direction);    /* Liste ausgeben    */
void print_reverse(Listnode *);


int main(void)
{
	/*
    p=(Listnode *)malloc(sizeof(Listnode));
    p->data = 15;
    p->next = NULL;
    pstart = p;
	/*
    p=(Listnode *)malloc(sizeof(Listnode));
    p->data = 27;
    p->next = NULL;
    pstart->next = p;
    p=(Listnode *)malloc(sizeof(Listnode));
    p->data = 99;
    p->next = NULL;
    pstart->next->next = p;
    */
	/*
    printf("%d\n", get_anzentries());
	put_entry(1, 77);
	put_entry(1,33);
	put_entry(2, 44);
    printall(FORWARD);
	printf("%d\n", get_anzentries());
    */


    p=(Listnode *)malloc(sizeof(Listnode));
    p->data = 15;
    p->next = NULL;
    pstart = p;
	
    get_anzentries();
	
	printall(FORWARD);
	put_entry(-1,71);
	put_entry(0,78);
	put_entry(2,74);
	put_entry(3,727);
	put_entry(4,72447);
	put_entry(5,72447);
	put_entry(6,72447);
	put_entry(7,72447);
	put_entry(8,72447);
	put_entry(9,72447);
	put_entry(10,72449);
	printall(FORWARD);
	printf("Break\n");
	printall(REVERSE);
	printf("Break\n");
	printall(FORWARD);
	printf("Break\n");
	printall(REVERSE);
    
	
	
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
	
    if(get_anzentries() == 0 && position >=0 && position <= 99)
    {
        p=(Listnode *)malloc(sizeof(Listnode));
        p->data = aktdata;
        p->next = NULL;
        pstart = p;
		
    }
	else
	{

    temp = (Listnode *)malloc(sizeof(Listnode));
    if(temp==NULL)
    {
        return NICHT_GENUG_SPEICHER; 
    }
    temp->next=NULL;
    temp->data = aktdata;
    if(position < 0)
    {
        return UNGUELTIGE_POSITION;
    }
    // Um den Codefreaktest zu bestehen
    else if(position>get_anzentries())
    {
        return UEBERTREIB_NICHT;
    }
    else if(position==0)
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
}


/* Unterprogramm zu Ausgabe aller Listenelemente
*  Parameter: direction  = FORWARD	vorwaerts
*                        = REVERSE	rueckwaerts
*  Return:    0          = alles OK
*         negative Werte = Fehler
*/
int printall(enum DIRECTION direction)
{
	if(get_anzentries() == 0)
	{
		return KEINE_ELEMENTE_VORHANDEN;
	}
    Listnode *ptr;
    if(direction == FORWARD)
    {
		
        ptr = pstart;
		if(ptr == NULL)
        {
            return KEINE_ELEMENTE_VORHANDEN;
        }
        printf("Die Daten der Elemente sind: \n");
        while(ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
    else if(direction == REVERSE)
    {
		if(get_anzentries() == 0)
	{
		return KEINE_ELEMENTE_VORHANDEN;
	}
		ptr = pstart;
        print_reverse(ptr);	

    }	
}

void print_reverse(Listnode *ptr)
{
	if(ptr == NULL)
	{
		return;
	}
	else
	{
	print_reverse(ptr->next);
	}
	printf("%d\n", ptr->data);
}

/* Unterprogramm zum Loeschen der gesamten Liste
*  Parameter: keine
*  Return:    0         = Loeschen OK
*         negative Werte = Fehler
*/
void del_list(void)  // TODO hat gar keinen Rueckgabewert 
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
	// Fehlermeldung wenn Position groesser als Vorhanden
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
        return 0;
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
	



    

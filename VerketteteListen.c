#include <stdio.h>
#include <stdlib.h>

typedef struct _Element {
	int wert_;
	struct _Element *next_;
} Element;

Element *liste;
Element *wurzel;

void ausgeben()
{
	liste = wurzel;
	while(liste != NULL)
	{
		printf("%d\n", liste->wert_);
		liste = liste->next_;
	}
}

void erzeuge_wurzel(int wert){
	
	Element *neu = malloc(sizeof(Element));
	neu->wert_ = wert;
	neu->next_ = NULL;
	
	liste = neu;
	wurzel = neu; 
}

void anhaengen(int neuer_wert)
{
	Element *neu = malloc(sizeof(Element));
	neu->wert_ = neuer_wert;
	neu->next_ = NULL;
	
	liste = wurzel;
	
	while(liste != NULL)
	{
		if (liste->next_ == NULL)
		{
			liste->next_ = neu;
			break;
		}
		else
		{
			liste = liste->next_;
		}
	}
}

void entfernen(int gesuchter_wert)
{
	liste = wurzel;
	
	Element *vorheriges_element = NULL;
	
	while(liste != NULL)
	{
		if(liste->wert_ == gesuchter_wert)
		{
			if(vorheriges_element == NULL)
			{
				wurzel == NULL;
				free(wurzel);
				wurzel = liste->next_;
			}
			else
			{
				vorheriges_element->next_ = NULL;
				free(vorheriges_element->next_);
				vorheriges_element->next_ = liste->next_;
			}
		}
		vorheriges_element = liste;
		liste = liste->next_;
	}
}

int main(void){
	
	erzeuge_wurzel(0);
	
	
	anhaengen(1);
	anhaengen(2);
	anhaengen(3);
	anhaengen(4);
	ausgeben();
	
	entfernen(3);
	ausgeben();
	
	
	
	
	return 0;
}
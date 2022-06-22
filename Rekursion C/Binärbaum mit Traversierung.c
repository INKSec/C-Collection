#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct _knoten {
	struct _knoten *links, *rechts;
	int wert;
} knoten;

int Summe (int von, int bis)
 {
   if (von < bis)
     return von + Summe (von + 1, bis);
   else
     return von;
 }

void einfuegen (knoten **ganzer_baum, int neu_wert);

		

	

int main(void){
	
	knoten *baum;
 
   baum = malloc (sizeof (knoten));
   baum->links = NULL;
   baum->rechts = NULL;
   baum->wert = 10;
 
   einfuegen (&baum, 2);
   einfuegen (&baum, 5);
   einfuegen (&baum, 17);
   einfuegen (&baum, 1);
  
	
	 printf ("Summe = %d\n", Summe (0, 100));
	
	return 0;
}

void einfuegen (knoten **ganzer_baum, int neu_wert)
{
	knoten *tmp, *neu_knoten;
	bool gefunden = false;
	
	tmp = (*ganzer_baum);
	
	while(!gefunden) {
		 if (neu_wert < tmp->wert)
         {
           if (tmp->links != NULL) 
             tmp = tmp->links;
           else
             gefunden = true;
         }
       else if (neu_wert == tmp->wert)
         gefunden = true;
       else
         {
           if (tmp->rechts != NULL)
             tmp = tmp->rechts;
           else
             gefunden = true;
         }
     }
   if (neu_wert != tmp->wert)
     {
       neu_knoten = malloc (sizeof (knoten));
       neu_knoten->links = NULL;
       neu_knoten->rechts = NULL;
       neu_knoten->wert = neu_wert;
       if (neu_wert < tmp->wert)
         tmp->links = neu_knoten;
       else
         tmp->rechts = neu_knoten;
     }
}
#include <stdio.h>
#include <stdlib.h>

	
typedef struct _knoten
{
	struct _knoten *knoten1;
	struct _knoten *knoten2;
	struct _knoten *knoten3;
	
	int wert;
}Knoten;

Knoten* erschaffeKnoten(int wert) {
	
	Knoten *k;
	k = (Knoten *)malloc(sizeof(Knoten));
	k->knoten1 = NULL;
	k->knoten2 = NULL;
	k->knoten3 = NULL;
	k->wert = wert;
	return k;
}

void print(Knoten *k) {
	
	if (k == NULL) {
		return;
	}
	printf("%d\n", k->wert);
	
	if(k->knoten1 != NULL) {
		print(k->knoten1);
	}
	
	if(k->knoten2 != NULL) {
		print(k->knoten2);
	}
	if (k->knoten3 != NULL) {
		print(k->knoten3);
	}
	
	
	
}

int main(void){
	
	Knoten *k1 = erschaffeKnoten(1);
	
	Knoten *k2 = erschaffeKnoten(2);
	k1->knoten1 = k2; 
	
	Knoten *k3 = erschaffeKnoten(5);
	k2->knoten1 = k3; 
	
	
	Knoten *k4 = erschaffeKnoten(6);
	k2->knoten2 = k4;
	
	Knoten *k5 = erschaffeKnoten(7);
	k2->knoten3 = k5;
	
	Knoten *k6 = erschaffeKnoten(3);
	k1->knoten2 = k6;
	
	Knoten *k7 = erschaffeKnoten(8);
	k6->knoten1 = k7;
	
	Knoten *k8 = erschaffeKnoten(9);
	k6->knoten2 = k8;
	
	Knoten *k9 = erschaffeKnoten(10);
	k6->knoten3 = k9;

	print(k1);
	
	
	  
	
 return 0;
}

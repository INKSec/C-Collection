#include <stdio.h>
#include <stdlib.h>

typedef struct listnode{
	unsigned artnr;
	char *artikel;
	double preis;
	
	struct listnode *next;
} Listnode;

Listnode *pstart=NULL, *p;


int main(void){
	
	p = (Listnode *)malloc(sizeof(Listnode));
	
	p->artnr = 123;
	p->artikel = "Poloshirt";
	p->preis = 9.90;
	
	printf("%d",p->artnr);
	
	pstart = (Listnode *)malloc(sizeof(Listnode));
	
	
	return 0;
}
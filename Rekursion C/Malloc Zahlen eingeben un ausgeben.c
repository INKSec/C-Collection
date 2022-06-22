#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	int grenze = 0;
 	int i = 0;
 	int eingabeWert = 0;
 	int summe = 0;
	
	int *ptrDatensatz;
	int *ptrFokusAufDatenelemente;
	
 
 	printf("Wieviele Werte moechten Sie eingeben?\n");
 	scanf("%d", &grenze);
	
	ptrDatensatz = (int *)malloc(sizeof(int)* grenze);
	ptrFokusAufDatenelemente = ptrDatensatz;
	
	for(i = 0; i < grenze; i++) {
		
		scanf("%d", &eingabeWert);
		*ptrFokusAufDatenelemente = eingabeWert;
		ptrFokusAufDatenelemente++;
	}
	for(i=0; i<grenze;i++) {
		printf("%d", *ptrDatensatz);
		ptrDatensatz++;
	}
	
	
	
}
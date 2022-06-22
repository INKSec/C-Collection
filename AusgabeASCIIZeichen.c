#include <stdio.h>

int main(void){

	char abfrage;
	
	printf("Bitte geben sie einen Buchstaben ein:\n");
	scanf("%c", &abfrage);
	
	printf("Der ASCII Code lautet: %d", abfrage);	
	return 0;
}
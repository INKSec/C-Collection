#include <stdio.h>
#define LAENGE 99

float mittelwert(int feld[], int elemente);

int main(void){
	
	float feld[LAENGE];
	int elemente = LAENGE +1;
	int i;
	for(i=0;i<elemente;i++){
		feld[i] = i+1;
		}
	
	
	printf("%f",mittelwert(&feld[0], elemente));
	
	
	
	
	
	return 0 ;
}

float mittelwert(int feld[0], int elemente){
	
	float summe = 0;
	float mittelwert;
	for(int i = 0; i<=elemente-1; i++){
		summe += feld[i];
		}
	mittelwert = summe / elemente;
	return mittelwert;
	
	
	}
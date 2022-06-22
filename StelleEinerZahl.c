#include <stdio.h>
#include <math.h>

int ziffer(int stelle, int zahl_1);
int anzahlZiffern (int zahl_1);



int main(void){
	int zahl_1;
	int zahl_2;
	int stelle;
	
	
	printf("Bitte geben Sie eine Zahl ein:\n");
	scanf("%d", &zahl_1);
	
	printf("Welche Stelle der Zahl soll ausgegeben werden?\n");
	scanf("%d", &stelle);
	
	
	
	printf("%d\n", ziffer(stelle, zahl_1));
	printf("%d", anzahlZiffern(zahl_1));
	
	return 0;
}



int ziffer(int stelle, int zahl_1) {
	
	int hilfsVariable;
	
	hilfsVariable = (int)pow(10, stelle-1);
	
	return (zahl_1/hilfsVariable%10);
	
	}

int anzahlZiffern (int zahl_1) {
	
	int hilfsVariable;
	int i;
	
	for (i=1; i<=10; i++)
    {
        hilfsVariable = (int)pow(10,i-1);
        if (!(zahl_1/hilfsVariable))
            return i-1;
    }
    return -1;
	
	
	}
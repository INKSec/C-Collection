#include <stdio.h>

int function(char test[], int anzahl, char gesucht);

int main(void){
	char test[4];
	test[0] = 'a';
	test[1] = 'b';
	test[2] = 'c';
	test[3] = 'd';
	test[4] = 'e';
	
	int anzahl = 5;
	char gesucht = 'A';
	
	printf("%d", function(&test[0], anzahl, gesucht));
	
	return 0;
}

int function(char test[], int anzahl, char gesucht){
	int i;
	int checker = 0;
	
	if(gesucht < 'a' || gesucht > 'z'){
		return -1;
	} else {
		for (i = 0;i<anzahl;i++){
			if (test[i] == gesucht){
				checker++;
				}
		}
		}
	if(checker != 0){
		return 1;
		} else {
		return 0;
	}
}	
	
		
	

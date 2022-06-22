#include <stdio.h>

int main(void){

	
	int alphabet;
		
	for(int i =1 ; i<11;i++){
		printf("%d ", i);
		alphabet = 97;
		for(int a=1;a<27;a++){
			
			
			printf("%c ", alphabet);
			alphabet++;
		}
		printf("\n");
	}
	
	return 0;
}
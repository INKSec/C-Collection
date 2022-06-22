#include <stdio.h>
#include <string.h>

int main(void){
	
	char string[20];
	char gedreht[20];
	int size;
	printf("Bitte String eingeben\n");
	scanf("%s", &string);
	
	size = strlen(string);
	
	for(int i = 0;i<size; i++){
		
		gedreht[i] = string[size-i-1];
		
		}
	printf("%s", gedreht);
	
	
	return 0;
}
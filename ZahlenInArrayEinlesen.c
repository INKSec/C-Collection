#include <stdio.h>

int main(void){
	
	int a[9];
	int i = 0;
	
	for(i=0;i<=9;i++){
		printf("Bitte Zahl eingeben\n");
		scanf("%d", &a[i]);
	}
	
	int z;
	for(z=9;z>=0;z--){
		printf("%d", a[z]);
	}
	
	
	
	return 0;
}
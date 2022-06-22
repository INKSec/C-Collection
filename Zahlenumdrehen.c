#include <stdio.h>

int main(void){
	
	int a;
	int b, c, d;
	
	printf("Geben Sie eine dreistellige Zahl ein\n");
	scanf("%d", &a);
	
	b = a / 100;
	c = (a / 10) - b*10;
	d = a % 10;
	
	
	printf("%d%d%d", d,c,b);
	
	return 0;
}
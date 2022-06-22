#include <stdio.h>
#include <string.h>

int main(void){
	
	char *string ="Hier koennte Ihre Werbung stehen";
	int size;
	
	size = strlen(string);
	printf("Laenge = %d", size);
	
	return 0;
}
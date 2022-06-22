#include <stdio.h>

int fakult( int a);

int main(void){
	
	printf("%d", fakult(5));
	
	
	return 0;
}

int fakult( int a) {
	if (a==1) {
	return 1;
}
	else {
	return a * fakult(a-1);
	}
}
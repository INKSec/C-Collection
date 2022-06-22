#include <stdio.h>

int zaehlen(int a);

int main(void){
	
	zaehlen(100);
	
	return 0;
}

int zaehlen(int a) {
	if(a>1) {
		printf("%d\n", a);
		return zaehlen(a-1);
	}
	return printf("%d\n", a);
} 
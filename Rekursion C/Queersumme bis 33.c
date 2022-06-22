#include <stdio.h>
int Queersumme(int n);

int main(void){
	
	printf("%d", Queersumme(66));
	
	return 1;
	
}

int Queersumme(int n) {
	return n<=9 ? n:Queersumme(Queersumme(n/10) + n%10);
}


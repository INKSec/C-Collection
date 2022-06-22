#include <stdio.h>

double geoReihe(int n);
double rekursiv(int n, double summe);

int main(void){
	printf("%f", rekursiv (2,1));
	
	
	return 0;
}

double geoReihe (int n) {
	int i;
	double a = 1, summe = 1;
	
	for(i = 0; i<n; i++) {
		a /= 2;
		summe += a;
	}
	return summe;
	
}

double rekursiv(int n, double summe) {
	if(n>1) {
		
		return rekursiv(n-1, summe/2);
	}
	else {
		return summe;
	}
} 



	






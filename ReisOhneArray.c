#include <stdio.h>
#include <float.h>

int main(void){
	
	int schachbrett[7][7];
	
	int i, z;
	double reiskoerner = 1;
	for(i=0; i<8;i++){
		for (z=0; z<7;z++){
			schachbrett[i][z] = reiskoerner;
			reiskoerner = reiskoerner*2;
		}
	}
	
	printf("%g", reiskoerner/2);
	return 0;
}
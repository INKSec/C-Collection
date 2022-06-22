#include <stdio.h>
#include <string.h>

struct person {
	char name[20];
	char vname[20];
	char gebdate[9];
	char geschlecht[10];
	unsigned long knr;
};
	


int main(void){
	
	struct person kunde[10];
	
	
	
	
	
	kunde[0].geschlecht[2] = "b";
	printf("%s", kunde[0].geschlecht[2]);
	
	
	return 0;
	
}
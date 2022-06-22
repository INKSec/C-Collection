#include <stdio.h>
#include <string.h>


int palindrom(char ein[]);

int main(void)
{
	
	
	char ein[256];
	
	
	printf("Bitte Wort eingeben\n");
	scanf("%s", &ein);
	
	palindrom(&ein[0]);
 
	
	
 return(0);
}

int palindrom(char ein[0]){
	int i, len;
	int zaehler = 0;
	
	len = strlen(ein);
	
	for(i=0;i<len;i++){
		
		if(ein[i] != ein[len-i-1])
		{
			zaehler = 1;
			break;
		}
	}
	if(zaehler){
		return 0;
		} else {
		return 1;
		}

	
	}
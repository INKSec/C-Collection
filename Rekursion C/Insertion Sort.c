#include <stdio.h>

void insertionSort(int array[], int size); 

int main(void){
	
	
	
	return 0;
}

void insertionSort(int array[], int size) 
{
	int i, j, v;
	for ( i = 1; i < size; i++) 
	{
		v = array[i]; 
		j = i;
		while ( ( j > 0 ) && ( array[j-1] > v ) ) 
		{
		array[j] = array[j-1];
		j = j-1;
 		}
 
		array[j] = v; 
 	}
}

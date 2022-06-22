#include <stdio.h>

void selectionSort (int array[ ], int size); 

int main(void){


	// minimum Index einfügen
		
	return 0;
}

void selectionSort (int array[ ], int size) 
{
 	int i, j, k;
 	for (i = 0; i < size - 1 ; i++) 
	{
 		j = minimumIndex (array, i+1, size-1); 
 		k = array[ i ]; 
 		if ( k > array[ j ] ) 
		{
 			array[ i ] = array[ j ];
 			array[ j ] = k;
 		}
 	}
}
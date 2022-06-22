#include <stdio.h>

int main(void){
	
	
	
	return 0;
}

// Für Selection Sort
// min_Index = zweites Element (i+1)
// max_index = size-1 
int minimumIndex(int array[], int min_index, int max_index)
{
	int i;
	int index = min_index;
	
	for( i = min_index + 1; i <= max_index; i++)
		{
		if (array[index] > array[i]) {
			index = i;
		}
	}
	return index;
}
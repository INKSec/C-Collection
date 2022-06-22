#include <stdio.h>

int main(void){
	
	int zaehler = 0;
 	int i, j, k, l, m, n; /* 6 Zahlen einer Kombination */
 
 	for (i = 1; i <= 49; i++)
 	{
 		for ( j = 1; j < i; j++ ) /* o.B.d.A.: j < i (s.o.) */
 		{
 			for ( k = 1; k < j; k++ )
 			{
 				for ( l = 1; l < k; l++ )
 					{
 						for ( m = 1; m < l; m++ )
						{
 							for ( n = 1; n < m; n++ )
							{
 								zaehler++; /* gueltige Kombination */
 }
 }
 }
 }
 }
 }
 
 printf("Anzahl Kombinationen beim Lotto: %d\n", zaehler);
	
	return 0;
}
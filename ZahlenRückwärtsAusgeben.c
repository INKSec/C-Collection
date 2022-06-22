#include <stdio.h>

int main(void){

    int a;

    printf("Bitte geben Sie eine ganze Zahl mit genau drei Ziffern ein:\n");
    scanf("%d", &a);

    int erste, zweite, dritte;

    erste = a % 10;
    zweite = (a % 100)/10;
    dritte = a / 100;

    printf("%d\n", erste);
    printf("%d\n", zweite);
    printf("%d", dritte);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

Listnode *Baumbau(char type, int value, Listnode *pleft, Listnode *pright);

typedef struct listnode {
	int number;
	char type;
	struct listnode *pright, *pleft;
} Listnode;
Listnode *proot, *left, *right;


int main(void){
	left = Baumbau('0', 3, NULL, NULL);
	right = Baumbau('0', 2, NULL, NULL);
	proot = Baumbau('*', 0, left, right);
	left = Baumbau('0', 8, NULL, NULL);
	right = Baumbau('0', 4, NULL, NULL);
	right = Baumbau('/', 0, left, right);
	proot = Baumbau('+', 0, proot, right);
	
	
	return 0;
}

Listnode *Baumbau(char type, int value, Listnode *pleft, Listnode *pright) {
	Listnode *proot;
	proot = (Listnode *)malloc(sizeof(Listnode));
	if(proot != NULL) {
	proot->type = type;
	proot->number = value;
	proot->pleft = pleft;
	proot->pright = pright;
	}
	return proot;
}
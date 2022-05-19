#include <stdio.h>
#include <stdlib.h>
#include "PilhaGenerica.h"

typedef struct{
	float x, y;
}Ponto;

void mostra_ponto( void *x ){
	Ponto *p = x;
	printf("(%.2f, %.2f)\n", p->x, p->y);
}

int main(int argc, char *argv[]) {
	PilhaGenerica p1;
	inicializa_pilha( &p1, 20, sizeof( Ponto ) );
	
	Ponto a = { 0, 0 };
	empilha( &p1, &a );
	
	Ponto b = { 5, 2 };
	empilha( &p1, &b );
	
	Ponto c = { -34, 98 };
	empilha( &p1, &c );
	
	
	mostra_pilha( p1, mostra_ponto );
	
	desaloca_pilha( &p1 );
	return 0;
}

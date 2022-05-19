#include "Matriz.h"
#include <stdlib.h>
#include <stdio.h>

void inicializa_matriz( Matriz *p, int l, int c ){
	int i, j;
	p->dados = malloc( sizeof( int * ) * l );
	for( i = 0 ; i < l ; i++ ){
		p->dados[i] = malloc( sizeof( int ) * c );
		for( j = 0 ; j < c ; j++ )
			p->dados[i][j] = 0;
	}
	p->lin = l;
	(*p).col = c; // Forma alternativa.
}

void mostra_matriz( Matriz x ){
	printf("Dados da Matriz (%dx%d):\n", x.lin, x.col);
	int i, j;
	for( i = 0 ; i < x.lin ; i++ ){
		for( j = 0 ; j < x.col ; j++ )
			printf("%4d ", x.dados[i][j]);
		printf("\n");
	}
	printf("\n");
}

void desaloca_matriz( Matriz *p ){
	int i;
	for( i = 0 ; i < p->lin ; i++ )
		free( p->dados[i] );
	free( p->dados );
}

int set_valor( Matriz *p, int i, int j, int valor ){
	if( i >= p->lin || j >= p->col )
		return COORD_INVALIDA;
	
	p->dados[i][j] = valor;
	return 1; // Sucesso
}

int carrega_arquivo( char *nome, Matriz *p ){
	FILE *f = fopen( nome, "rt" );
	if( f == NULL )
		return 0; // Arquivo não existe!
	
	int lin, col, i, j, valor;
	fscanf( f, "%d %d", &lin, &col);
	inicializa_matriz( p, lin, col );
	for( i = 0 ; i < lin ; i++ )
		for( j = 0 ; j < col ; j++ ){
			fscanf( f, "%d", &valor);
			set_valor( p, i, j, valor );
		}
	
	fclose( f );
	return 1; // Sucesso.
}



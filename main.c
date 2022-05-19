#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"
#include "PilhaGenerica.h"

typedef struct{
	float x, y;
}Ponto;

int main(int argc, char *argv[]) {
  Matriz m;

  if( !carrega_arquivo( "entrada.txt", &m ) ){
		printf("ERRO NO ARQUIVO DE ENTRADA!\n");
		return -1;
	}

  mostra_matriz( m );

  char resp;

  PilhaGenerica p1;
	inicializa_pilha( &p1, 20, sizeof( Ponto ) );


  int valor;
  Ponto coord;

  printf("Digite o valor: ");
  scanf("%d", &valor);

  printf("Digite as coordenadas (x, y): ");
  scanf("%d%d", &coord.x, &coord.y);
  
  empilha(&p1, &coord);

  while (pilha_vazia(p1)==0)
  {
    desempilha();
  }
    

  desaloca_matriz( &m );
  desaloca_pilha( &p1 );


  return 0;
}
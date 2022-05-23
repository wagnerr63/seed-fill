#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"
#include "PilhaGenerica.h"

typedef struct{
	float x, y;
}Ponto;

void mostra_ponto( void *x ){
	Ponto *p = x;
	printf("(%.2f, %.2f)\n", p->x, p->y);
}

void busca_vizinhos(Ponto p, PilhaGenerica *pilha_vizinhos, Matriz m) {
  int i ;

  // esquerda
  if (p.y-1 >= 0) {
    Ponto p1;
    p1.x = p.x;
    p1.y = p.y-1;
    empilha(pilha_vizinhos, &p1);
  }

  // cima
  if (p.x-1 >= 0) {
    Ponto p2;
    p2.x = p.x-1;
    p2.y = p.y;
    empilha(pilha_vizinhos, &p2);
  }

  // direita
  if (p.y+1 <= m.col) {
    Ponto p3;
    p3.x = p.x;
    p3.y = p.y+1;
    empilha(pilha_vizinhos, &p3);
  }

  // baixo
  if (p.x+1 <= m.lin) {
    Ponto p4;
    p4.x = p.x+1;
    p4.y = p.y;
    empilha(pilha_vizinhos, &p4);
  }

}

void cria_novo_arquivo_matriz(Matriz m) {
    FILE *f = fopen("saida.txt", "w");
    // [TODO] Escrever no arquivo a nova matriz
    fclose(f);
}

int main(int argc, char *argv[]) {
  Matriz m;
  Matriz m_modificada;

  if( !carrega_arquivo( "entrada.txt", &m ) ){
		printf("ERRO NO ARQUIVO DE ENTRADA!\n");
		return -1;
	}

  mostra_matriz( m );

  char resp;

  PilhaGenerica p1;
	inicializa_pilha( &p1, 20, sizeof( Ponto ) );


  int nova_cor = 5;
  Ponto coord;

  coord.x = 3;
  coord.y = 1;

  int cor_orig = m.dados[(int)coord.x][(int)coord.y];
  
  empilha(&p1, &coord);

  while (pilha_vazia(p1)==0)
  {
    desempilha(&p1, &coord);
    if (m.dados[(int)coord.x][(int)coord.y] != nova_cor) {
      set_valor(&m, (int)coord.x, (int)coord.y, nova_cor);
      
      PilhaGenerica pilha_vizinhos;
	    inicializa_pilha( &pilha_vizinhos, 4, sizeof( Ponto ) );
      busca_vizinhos(coord, &pilha_vizinhos, m);

      while (pilha_vazia(pilha_vizinhos)==0)
      {
        Ponto vizinho;
        le_topo(pilha_vizinhos, &vizinho);

        if (m.dados[(int) vizinho.x][(int) vizinho.y] == cor_orig) {
          empilha(&p1, &vizinho);
        }
        desempilha(&pilha_vizinhos, &vizinho);
      }
      

      desaloca_pilha( &pilha_vizinhos);
    }
  }
  
  mostra_matriz( m );
  cria_novo_arquivo_matriz(m);
    
  desaloca_matriz( &m );
  desaloca_pilha( &p1 );


  return 0;
}
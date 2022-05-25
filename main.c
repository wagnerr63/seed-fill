#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"
#include "PilhaGenerica.h"

typedef struct{
	float x, y;
}Ponto;

int valida_ponto( Ponto p, int l, int c ){
  return p.x >=0 && p.x < l && p.y >=0 && p.y < c;
}


void busca_vizinhos(Ponto p, PilhaGenerica *pilha_principal, Matriz m, int cor_orig) {
  int i;
  int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

  for( i = 0; i < 4 ; i++){
    Ponto p1;
    p1.x = p.x+dx[i];
    p1.y = p.y+dy[i];
    if( valida_ponto( p1, m.lin, m.col ) && m.dados[(int) p1.x][(int) p1.y] == cor_orig)
      empilha(pilha_principal, &p1);
  }

}

void cria_novo_arquivo_matriz(Matriz m) {
    FILE *f = fopen("saida.txt", "w");
    
    fprintf(f, "%4d %4d\n", m.lin, m.col);
    int i, j;
    for( i = 0 ; i < m.lin ; i++ ){
      for( j = 0 ; j < m.col ; j++ )
        fprintf(f, "%4d ", m.dados[i][j]);
        fprintf(f, "\n");
    }
    fprintf(f, "\n");

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

  Ponto coord;
  int nova_cor;

  do{
	printf("Qual pixel deseja mudar? (x, y) \n");
	scanf("%f", &coord.x);
	scanf("%f", &coord.y);
	if(coord.x > m.lin || coord.y > m.col){
		prinft("O ponto escolhido deve estar dentro dos limites da matriz (%dx%d) \n", &m.lin, &m.col);
	}
  }while(coord.x <= m.lin && coord.y <= m.col);
	

  printf("Que valor deseja para a cor do pixel? \n");
  scanf("%d", &nova_cor);

  int cor_orig = m.dados[(int)coord.x][(int)coord.y];
  
  empilha(&p1, &coord);

  while (pilha_vazia(p1)==0)
  {
    desempilha(&p1, &coord);

    if (m.dados[(int)coord.x][(int)coord.y] != nova_cor) {
      set_valor(&m, (int)coord.x, (int)coord.y, nova_cor);
      
      busca_vizinhos(coord, &p1, m, cor_orig);

    }
  }
  
  mostra_matriz( m );
  cria_novo_arquivo_matriz(m);
    
  desaloca_matriz( &m );
  desaloca_pilha( &p1 );


  return 0;
}

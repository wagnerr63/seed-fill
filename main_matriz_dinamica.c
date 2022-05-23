// #include <stdio.h>
// #include <stdlib.h>
// #include "Matriz.h"

// int main(int argc, char *argv[]) {
// 	Matriz m;
	
// 	//inicializa_matriz( &m, 5, 5 );
	
// 	if( !carrega_arquivo( "entrada.txt", &m ) ){
// 		printf("ERRO NO ARQUIVO DE ENTRADA!\n");
// 		return -1;
// 	}
	
// 	mostra_matriz( m );
	
// 	char resp;
	
// 	do{
	
// 		int x, y, valor;
// 		printf("Digite o valor: ");
// 		scanf("%d", &valor);
// 		printf("Digite as coordenadas (x, y): ");
// 		scanf("%d%d", &x, &y);
	
// 		if( set_valor( &m, x, y, valor ) ==  COORD_INVALIDA )
// 			printf("Coordenadas invalidas!\n");
	
// 		mostra_matriz( m );
	
// 		printf("Deseja continuar modificando a matriz (s/n)? ");
// 		scanf(" %c", &resp);
// 		system("CLS");
// 	}while( resp == 's' );
	
// 	desaloca_matriz( &m );
	
// 	return 0;
// }

#define COORD_INVALIDA -1

typedef struct{
	int **dados;
	int lin, col;
}Matriz;

void inicializa_matriz( Matriz *p, int l, int c );
void mostra_matriz( Matriz x );
void desaloca_matriz( Matriz *p );
int set_valor( Matriz *p, int i, int j, int valor );
int carrega_arquivo( char *nome, Matriz *p );


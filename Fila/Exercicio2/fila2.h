typedef struct fila Fila;

typedef int tipo;

Fila *fila_cria();
void fila_insere(Fila *q, tipo elem);
tipo fila_retira(Fila *q);
int fila_vazia(Fila *q);
int fila_cheia(Fila *q);
void fila_imprime(Fila *q);
int fila_tamanho(Fila *q);
Fila *fila_libera(Fila *q);
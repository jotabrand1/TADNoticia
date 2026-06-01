#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H
#include "Noticia.h"

typedef struct noListaEnc {
    Noticia* info;
    struct noListaEnc* prox;
} NoListaEnc;

void criarEncadeada(NoListaEnc** l);
int estaVaziaEncadeada(NoListaEnc** l);
void insereNoInicio(NoListaEnc** l, Noticia* v);
void removerEncadeada(NoListaEnc** l, const char* palavraChave);
void imprimirEncadeada(NoListaEnc** l);
int retornaConfi(NoListaEnc** l);
int retornaSusp(NoListaEnc** l);

#endif
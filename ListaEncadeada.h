#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include "Noticia.h"

/* Nó da lista simplesmente encadeada — info é ponteiro para Noticia */
typedef struct noListaEnc {
    Noticia*          info;
    struct noListaEnc* prox;
} NoListaEnc;

/* Protótipos */
void criarEncadeada(NoListaEnc** l);
int  estaVaziaEncadeada(NoListaEnc** l);
void insereNoInicio(NoListaEnc** l, Noticia* v);
void removerEncadeada(NoListaEnc** l, const char* palavraChave);
void imprimirEncadeada(NoListaEnc** l);
int  retornaConfi(NoListaEnc** l);
int  retornaSusp(NoListaEnc** l);
void liberarEncadeada(NoListaEnc** l);

#endif /* LISTAENCADEADA_H */
#ifndef LISTACABCAU_H
#define LISTACABCAU_H

#include "Noticia.h"

/* Nó da lista com cabeça e cauda — info armazenado por valor */
typedef struct noLista {
    Noticia          info;
    struct noLista*  prox;
} NoLista;

/* Lista encadeada com sentinelas de cabeça e cauda */
typedef struct lista {
    NoLista* cab; /* Nó sentinela de cabeça */
    NoLista* cau; /* Nó sentinela de cauda  */
} Lista;

/* Protótipos */
void criarCabCau(Lista* l);
int  estaVaziaCabCau(Lista* l);
void inserirCabCau(Lista* l, Noticia v);
void removerCabCau(Lista* l, int id);
void buscarNoticiaPorPalavraCabCau(Lista* l, const char* palavraChave);
void imprimirCabCau(Lista* l);
int  retornaQtd(Lista* l);
void liberarCabCau(Lista* l);

#endif /* LISTACABCAU_H */
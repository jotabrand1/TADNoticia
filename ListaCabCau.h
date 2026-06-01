#ifndef LISTACABCAU_H
#define LISTACABCAU_H
#include "Noticia.h"

typedef struct noLista{
    Noticia info;
    struct noLista* prox;
}NoLista;

typedef struct lista{
    NoLista* cab;
    NoLista* cau;
}Lista;

void criarCabCau(Lista*l);
int estaVaziaCabCau(Lista*l);
void inserirCabCau(Lista*l, Noticia v);
void removerCabCau(Lista*l, int id);
void buscarNoticiaPorPalavraCabCau(Lista* l, const char* palavraChave);
void imprimirCabCau(Lista*l);
int retornaQtd(Lista*l);


#endif
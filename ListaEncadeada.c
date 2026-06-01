#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEncadeada.h"

void criarEncadeada(NoListaEnc** l) {
    *l = NULL;
}

int estaVaziaEncadeada(NoListaEnc** l) {
    return (*l == NULL);
}

void insereNoInicio(NoListaEnc** l, Noticia* v) {
    NoListaEnc* novo = (NoListaEnc*)malloc(sizeof(NoListaEnc));
    if (novo != NULL) {
        novo->info = v;
        novo->prox = *l;
        *l = novo;
    }
}

void removerEncadeada(NoListaEnc** l, const char* palavraChave) {
    NoListaEnc *p, *ant = NULL;
    int removeu = 0;
    if (!estaVaziaEncadeada(l)) {
        for (p = *l; p != NULL; ) {
            if (strstr(p->info->titulo, palavraChave) != NULL || strstr(p->info->conteudo, palavraChave) != NULL) {
                NoListaEnc* aux = p;
                if (ant == NULL) {
                    *l = p->prox;
                } else {
                    ant->prox = p->prox;
                }
                p = p->prox;
                free(aux->info); 
                free(aux);
                removeu = 1;
                printf("Noticia removida com sucesso!\n");
            } else {
                ant = p;
                p = p->prox;
            }
        }
        if (!removeu) {
            printf("Nenhuma noticia encontrada com essa palavra.\n");
        }
    } else {
        printf("A lista de verificadas esta vazia.\n");
    }
}

void imprimirEncadeada(NoListaEnc** l) {
    NoListaEnc* p;
    if (!estaVaziaEncadeada(l)) {
        for (p = *l; p != NULL; p = p->prox) {
            
            imprimirNoticia(p->info); 
        }
    }
}

int retornaConfi(NoListaEnc** l) {
    NoListaEnc* p;
    int qtd = 0;
    for (p = *l; p != NULL; p = p->prox) {
        if (p->info != NULL && p->info->clasf == 2) {
            qtd++;
        }
    }
    return qtd;
}

int retornaSusp(NoListaEnc** l) {
    NoListaEnc* p;
    int qtd = 0;
    for (p = *l; p != NULL; p = p->prox) {
        if (p->info != NULL && p->info->clasf == 3) {
            qtd++;
        }
    }
    return qtd;
} 
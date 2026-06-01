#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaCabCau.h"

/*
 * criarCabCau
 * Inicializa a lista alocando os nós sentinelas de cabeça e cauda.
 */
void criarCabCau(Lista* l) {
    l->cab       = (NoLista*) malloc(sizeof(NoLista));
    l->cau       = (NoLista*) malloc(sizeof(NoLista));
    l->cab->prox = l->cau;
    l->cau->prox = NULL;
}

/*
 * estaVaziaCabCau
 * Retorna 1 se a lista não tiver elementos (cab aponta direto para cau).
 */
int estaVaziaCabCau(Lista* l) {
    return (l->cab->prox == l->cau);
}

/*
 * inserirCabCau
 * Insere uma nova notícia sempre no início (logo após o nó cabeça).
 */
void inserirCabCau(Lista* l, Noticia v) {
    NoLista* novo = (NoLista*) malloc(sizeof(NoLista));

    if (novo != NULL) {
        novo->info   = v;
        novo->prox   = l->cab->prox;
        l->cab->prox = novo;
    } else {
        printf("Erro: nao foi possivel alocar espaco.\n");
    }
}

/*
 * removerCabCau
 * Remove da lista o nó cuja notícia possui o id informado.
 */
void removerCabCau(Lista* l, int id) {
    if (estaVaziaCabCau(l)) {
        printf("Lista de pendentes vazia.\n");
        return;
    }

    NoLista* ant = l->cab;
    NoLista* p   = l->cab->prox;

    /* Percorre até encontrar o id ou alcançar a cauda */
    while (p != l->cau && p->info.id != id) {
        ant = p;
        p   = p->prox;
    }

    if (p == l->cau) {
        printf("Noticia com ID %d nao encontrada.\n", id);
    } else {
        ant->prox = p->prox;
        free(p);
        printf("Noticia removida com sucesso.\n");
    }
}

/*
 * buscarNoticiaPorPalavraCabCau
 * Exibe todas as notícias pendentes cujo título ou conteúdo
 * contenha a palavra-chave fornecida (busca com strstr).
 */
void buscarNoticiaPorPalavraCabCau(Lista* l, const char* palavraChave) {
    if (estaVaziaCabCau(l)) {
        printf("Nenhuma noticia pendente encontrada.\n");
        return;
    }

    int encontrou = 0;
    NoLista* p;

    for (p = l->cab->prox; p != l->cau; p = p->prox) {
        if (strstr(p->info.titulo,   palavraChave) != NULL ||
            strstr(p->info.conteudo, palavraChave) != NULL) {
            imprimirNoticia(&(p->info));
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma noticia encontrada com a palavra-chave \"%s\".\n", palavraChave);
    }
}

/*
 * imprimirCabCau
 * Imprime todas as notícias da lista de pendentes.
 */
void imprimirCabCau(Lista* l) {
    if (estaVaziaCabCau(l)) {
        printf("Nenhuma noticia pendente encontrada.\n"); /* "encontrada" — corrige erro de digitação */
        return;
    }

    NoLista* p;
    for (p = l->cab->prox; p != l->cau; p = p->prox) {
        imprimirNoticia(&(p->info));
    }
}

/*
 * retornaQtd
 * Retorna o número de notícias presentes na lista de pendentes.
 */
int retornaQtd(Lista* l) {
    NoLista* p;
    int qtd = 0;

    for (p = l->cab->prox; p != l->cau; p = p->prox) {
        qtd++;
    }

    return qtd;
}

/*
 * liberarCabCau
 * Libera todos os nós da lista, incluindo os sentinelas.
 * Deve ser chamada ao encerrar o programa para evitar memory leaks.
 */
void liberarCabCau(Lista* l) {
    NoLista* p = l->cab->prox;
    NoLista* aux;

    while (p != l->cau) {
        aux = p->prox;
        free(p);
        p = aux;
    }

    free(l->cab);
    free(l->cau);
    l->cab = NULL;
    l->cau = NULL;
}
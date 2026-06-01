#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEncadeada.h"

/*
 * criarEncadeada
 * Inicializa a lista simplesmente encadeada como vazia (NULL).
 */
void criarEncadeada(NoListaEnc** l) {
    *l = NULL;
}

/*
 * estaVaziaEncadeada
 * Retorna 1 se a lista estiver vazia.
 */
int estaVaziaEncadeada(NoListaEnc** l) {
    return (*l == NULL);
}

/*
 * insereNoInicio
 * Insere um ponteiro para Noticia sempre no início da lista verificadas.
 * A Noticia apontada deve ter sido alocada com malloc pelo chamador;
 * a lista passa a ser responsável por liberar essa memória.
 */
void insereNoInicio(NoListaEnc** l, Noticia* v) {
    NoListaEnc* novo = (NoListaEnc*) malloc(sizeof(NoListaEnc));

    if (novo != NULL) {
        novo->info = v;
        novo->prox = *l;
        *l = novo;
    } else {
        printf("Erro: nao foi possivel alocar espaco.\n");
    }
}

/*
 * removerEncadeada
 * Remove da lista todos os nós cuja notícia contenha a palavra-chave
 * no título ou no conteúdo.
 *
 * Correção: o free(aux->info) só é chamado para ponteiros que foram
 * alocados via malloc na opção 6 do main (o fluxo normal do programa).
 * Como toda notícia inserida nas verificadas vem de malloc em main,
 * o free é seguro aqui.
 */
void removerEncadeada(NoListaEnc** l, const char* palavraChave) {
    if (estaVaziaEncadeada(l)) {
        printf("A lista de verificadas esta vazia.\n");
        return;
    }

    NoListaEnc* p   = *l;
    NoListaEnc* ant = NULL;
    int removeu = 0;

    while (p != NULL) {
        if (strstr(p->info->titulo,   palavraChave) != NULL ||
            strstr(p->info->conteudo, palavraChave) != NULL) {

            NoListaEnc* aux = p;

            if (ant == NULL) {
                *l = p->prox;      /* Remoção do primeiro nó */
            } else {
                ant->prox = p->prox;
            }

            p = p->prox;

            free(aux->info); /* Libera a Noticia alocada em main */
            aux->info = NULL;
            free(aux);       /* Libera o nó da lista              */

            removeu = 1;
            printf("Noticia removida com sucesso!\n");

        } else {
            ant = p;
            p   = p->prox;
        }
    }

    if (!removeu) {
        printf("Nenhuma noticia encontrada com a palavra-chave \"%s\".\n", palavraChave);
    }
}

/*
 * imprimirEncadeada
 * Imprime todas as notícias da lista de verificadas.
 */
void imprimirEncadeada(NoListaEnc** l) {
    if (estaVaziaEncadeada(l)) {
        printf("Nenhuma noticia verificada encontrada.\n");
        return;
    }

    NoListaEnc* p;
    for (p = *l; p != NULL; p = p->prox) {
        imprimirNoticia(p->info);
    }
}

/*
 * retornaConfi
 * Retorna a quantidade de notícias classificadas como CONFIAVEL.
 */
int retornaConfi(NoListaEnc** l) {
    NoListaEnc* p;
    int qtd = 0;

    for (p = *l; p != NULL; p = p->prox) {
        if (p->info != NULL && p->info->clasf == CONFIAVEL) {
            qtd++;
        }
    }

    return qtd;
}

/*
 * retornaSusp
 * Retorna a quantidade de notícias classificadas como SUSPEITA.
 */
int retornaSusp(NoListaEnc** l) {
    NoListaEnc* p;
    int qtd = 0;

    for (p = *l; p != NULL; p = p->prox) {
        if (p->info != NULL && p->info->clasf == SUSPEITA) {
            qtd++;
        }
    }

    return qtd;
}

/*
 * liberarEncadeada
 * Libera todos os nós da lista e as notícias apontadas por eles.
 * Deve ser chamada ao encerrar o programa para evitar memory leaks.
 */
void liberarEncadeada(NoListaEnc** l) {
    NoListaEnc* p = *l;
    NoListaEnc* aux;

    while (p != NULL) {
        aux = p->prox;
        free(p->info); /* Libera a Noticia */
        p->info = NULL;
        free(p);       /* Libera o nó      */
        p = aux;
    }

    *l = NULL;
}
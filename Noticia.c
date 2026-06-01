#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noticia.h"

/*
 * criarNoticia
 * Aloca e preenche uma nova notícia via entrada do usuário.
 * A classificação inicial é sempre EM_ANALISE (notícias recém-cadastradas
 * ficam na fila de pendentes e serão classificadas depois pela opção 6).
 * Retorna ponteiro para a notícia alocada, ou NULL em caso de falha.
 */
Noticia* criarNoticia() {
    static int gerenciadorId = 1; /* Contador de ID único, incrementado a cada criação */

    Noticia* noticia = (Noticia*) malloc(sizeof(Noticia));

    if (noticia == NULL) {
        printf("Erro: nao foi possivel alocar espaco na memoria.\n");
        return NULL; /* Retorno explícito em caso de falha — corrige ausência anterior */
    }

    /* ID gerado automaticamente pelo programa */
    noticia->id = gerenciadorId++;
    printf("Noticia criada com ID: %d\n", noticia->id);

    printf("Digite a data da noticia (DD/MM/AAAA): ");
    scanf("%10s", noticia->data);

    printf("Digite o titulo da noticia: ");
    scanf(" %999[^\n]", noticia->titulo);

    printf("Digite o conteudo da noticia: ");
    scanf(" %999[^\n]", noticia->conteudo);

    printf("Digite a fonte da noticia: ");
    scanf(" %999[^\n]", noticia->fonte);

    /*
     * Classificação forçada como EM_ANALISE.
     * Notícias recém-cadastradas sempre entram como pendentes;
     * a reclassificação acontece na opção 6 do menu.
     */
    noticia->clasf = EM_ANALISE;

    return noticia;
}

/*
 * imprimirNoticia
 * Exibe os campos de uma notícia formatados no terminal.
 */
void imprimirNoticia(Noticia* noticia) {
    if (noticia == NULL) {
        printf("Nenhuma noticia para exibir.\n");
        return;
    }

    printf("--------------------------------\n");
    printf("ID       : %d\n",   noticia->id);
    printf("Data     : %s\n",   noticia->data);
    printf("Titulo   : %s\n",   noticia->titulo);
    printf("Fonte    : %s\n",   noticia->fonte);
    printf("Conteudo : %s\n",   noticia->conteudo);
    printf("Classif. : ");

    switch (noticia->clasf) {
        case EM_ANALISE: printf("EM ANALISE\n"); break;
        case CONFIAVEL:  printf("CONFIAVEL\n");  break;
        case SUSPEITA:   printf("SUSPEITA\n");   break;
        default:         printf("DESCONHECIDA\n"); break;
    }

    printf("--------------------------------\n");
}

/*
 * liberarNoticia
 * Libera a memória apontada por *noticia e zera o ponteiro.
 */
void liberarNoticia(Noticia** noticia) {
    if (noticia != NULL && *noticia != NULL) {
        free(*noticia);
        *noticia = NULL;
    }
}
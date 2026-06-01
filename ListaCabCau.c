#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaCabCau.h"

void criarCabCau(Lista*l){
    l->cab = (NoLista*) malloc(sizeof(NoLista));
    l->cau = (NoLista*) malloc(sizeof(NoLista));
    l->cab->prox = l->cau;
    l->cau->prox = NULL;
}
int estaVaziaCabCau(Lista*l){
    return (l->cab->prox == l->cau);
}

void inserirCabCau(Lista*l, Noticia v){
    NoLista* novo = (NoLista*) malloc(sizeof(NoLista));

    if(novo != NULL){
        novo->info = v;
        novo->prox = l->cab->prox;
        l->cab->prox= novo;
        
    }else{
        printf("Não foi possível alocar espaço");
    }
}

void removerCabCau(Lista*l, int id){
    NoLista*p;
    NoLista* ant = l->cab;
    if(!estaVaziaCabCau(l)){
        for(p = l->cab->prox;p != l->cau && p->info.id != id;p = p->prox){
            ant  = p;
        }

    
        if(p == l->cau){
            printf("Noticia não encontrada\n");
        }else{
            ant->prox = p->prox;
            free(p);
        }
    }

    
}

void buscarNoticiaPorPalavraCabCau(Lista* l, const char* palavraChave){
    NoLista*p;
    if(!estaVaziaCabCau(l)){
        for(p = l->cab->prox; p != l->cau; p = p->prox){
            if (strstr(p->info.titulo, palavraChave) != NULL || 
                strstr(p->info.conteudo, palavraChave) != NULL) {
                
                // Exibe a notícia encontrada
                imprimirNoticia(&(p->info)); 
                printf("--------------------------------------------------\n");
               
            }
        }
    }
}

void imprimirCabCau(Lista*l){
    NoLista*p;

   if(!estaVaziaCabCau(l)){
        for(p = l->cab->prox;p != l->cau;p = p->prox ){
            imprimirNoticia(&(p->info));
        }
    }else{
        printf("Nenhuma noticia pendente encotrada");
    }
}

int retornaQtd(Lista*l){
    NoLista* p;
    int qtd = 0;

    for(p = l->cab->prox; p != l->cau; p = p->prox){
        qtd++;
    }

    return qtd;

}
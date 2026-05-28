#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noticia.h"


Noticia* criarNoticia(){
    static int gerenciadorId = 1;
    Noticia* noticia = (Noticia*)malloc(sizeof(Noticia));
    
    if(noticia != NULL){

        
        noticia->id = gerenciadorId++;
        printf("Noticia criada automaticamente com o ID: %d\n", noticia->id);

        printf("Digite a data da noticia (DD/MM/AAAA): ");
        scanf("%10s", noticia->data);

        
    
        printf("Digite o titulo da noticia: ");
        scanf(" %999[^\n]", noticia->titulo);

        

        printf("Digite o conteudo da noticia: ");
        scanf(" %999[^\n]", noticia->conteudo); 

       

        printf("Digite a fonte da noticia: ");
        scanf(" %999[^\n]", noticia->fonte);

        
        int opcao;
        printf("Digite a classificacao da noticia (1 - EmAnalise, 2 - Confiavel, 3 - Suspeita): ");
        scanf("%d", &opcao);
        noticia->clasf = opcao;



        return noticia;
    }else{
        printf("Nao foi possivel alocar espaço na memoria");
    }
    

}

void imprimirNoticia(Noticia*noticia){
    if(noticia != NULL){
        printf("--------------------------------");
        printf("\n");
        printf("Id da noticia: %d", noticia->id);
        printf("\n");
        printf("Data da noticia: %s", noticia->data);
        printf("\n");
        printf("Titulo da noticia: %s", noticia->titulo);
        printf("\n");
        printf("fonte da noticia: %s", noticia->fonte);
        printf("\n");


        printf("Classificação da noticia:" );

        switch (noticia->clasf)
        {
            case EM_ANALISE:
                printf("EM ANÁLISE");
                break;
            case CONFIAVEL:
                printf("CONFIAVEL");
                break;
            case SUSPEITA:
                printf("SUSPEITA");
                break;    
            
            default:
                printf("DESCONHECIDA");
                break;
        }
        printf("\n");
        printf("--------------------------------");
        printf("\n");
    }else{
        printf("Não há nenhuma notícia\n");
    }
    
}

void liberarNoticia(Noticia**noticia){
    if(noticia != NULL && *noticia != NULL){
        free(*noticia);
        *noticia = NULL;
    }
    
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noticia.h"


int main() {
    Noticia* noticia1 = criarNoticia();
    imprimirNoticia(noticia1);
    liberarNoticia(&noticia1);
    imprimirNoticia(noticia1);

    int opcao;
    

    do{
        printf("----------------MENU------------------");
        printf("1 - Adicionar nova noticia\n");
        printf("2 - Remover notícia pendente por id\n");
        printf("3 - Remover notícia verificada por palavra-chave\n");
        printf("4 - Buscar noticias pendentes por palavra-chave\n");
        printf("5 - Imprimir as noticias\n");
        printf("6 - Classificar notícias\n");
        printf("7 - Imprimir quantidade de notícias por categoria\n");
        printf ("8 - Sair\n");
        printf("Escolha uma opção: \n");
        printf("-------------------------------------------");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;        
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            /* code */
            break;        
        default:
            printf("Opcao invalida\n");
            break;
        }
    }while(opcao != 0);

    return 0;
}
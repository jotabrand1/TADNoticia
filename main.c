#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noticia.h"
#include "ListaCabCau.h"
#include "ListaEncadeada.h"
 
int main() {
    Lista       listaPendentes;  
    NoListaEnc* listaVerificadas; 
 
    criarCabCau(&listaPendentes);
    criarEncadeada(&listaVerificadas);
 
    int  opcao;
    int  id;
    char palavra[100];
 
    do {
        printf("\n----------------MENU------------------\n");
        printf("1 - Adicionar nova noticia\n");
        printf("2 - Remover noticia pendente por id\n");
        printf("3 - Remover noticia verificada por palavra-chave\n");
        printf("4 - Buscar noticias pendentes por palavra-chave\n");
        printf("5 - Imprimir as noticias\n");
        printf("6 - Classificar noticias\n");
        printf("7 - Imprimir quantidade de noticias por categoria\n");
        printf("8 - Sair\n");
        printf("--------------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
 
        switch (opcao) {
 
           
            case 1: {
                Noticia* nova = criarNoticia();
                if (nova != NULL) {
                    inserirCabCau(&listaPendentes, *nova);
                    free(nova); 
                    printf("Noticia adicionada com sucesso!\n");
                }
                break;
            }
 
            
            case 2:
                printf("Digite o ID da noticia a remover: ");
                scanf("%d", &id);
                if (id > 0) {
                    removerCabCau(&listaPendentes, id);
                } else {
                    printf("ID invalido.\n");
                }
                break;
 
           
            case 3:
                printf("Digite a palavra-chave para remover das verificadas: ");
                scanf(" %99[^\n]", palavra);
                removerEncadeada(&listaVerificadas, palavra);
                break;
 
           
            case 4:
                printf("Digite a palavra-chave para buscar nas pendentes: ");
                scanf(" %99[^\n]", palavra);
                buscarNoticiaPorPalavraCabCau(&listaPendentes, palavra);
                break;
 
           
            case 5: {
                
                int subOpcao;
                printf("\nQuais noticias deseja imprimir?\n");
                printf("1 - Pendentes\n");
                printf("2 - Verificadas\n");
                printf("3 - Ambas\n");
                printf("Escolha: ");
                scanf("%d", &subOpcao);
 
                if (subOpcao == 1 || subOpcao == 3) {
                    printf("\n--- NOTICIAS PENDENTES ---\n");
                    imprimirCabCau(&listaPendentes);
                }
                if (subOpcao == 2 || subOpcao == 3) {
                    printf("\n--- NOTICIAS VERIFICADAS ---\n");
                    imprimirEncadeada(&listaVerificadas);
                }
                if (subOpcao < 1 || subOpcao > 3) {
                    printf("Opcao invalida.\n");
                }
                break;
            }
 
            
            case 6: {
                if (estaVaziaCabCau(&listaPendentes)) {
                    printf("Nenhuma noticia pendente para classificar.\n");
                    break;
                }
 
                int ids[1000];
                int total = 0;
                NoLista* p;
 
                
                for (p = listaPendentes.cab->prox;
                     p != listaPendentes.cau;
                     p = p->prox) {
                    ids[total++] = p->info.id;
                }
 
                
                int i;
                for (i = 0; i < total; i++) {
                    
                    int achou = 0;
                    for (p = listaPendentes.cab->prox;
                         p != listaPendentes.cau;
                         p = p->prox) {
                        if (p->info.id == ids[i]) {
                            achou = 1;
                            break;
                        }
                    }
                    if (!achou) continue;
 
                    imprimirNoticia(&(p->info));
 
                    int novaClassif;
                    printf("Defina a nova classificacao:\n");
                    printf("1 - Permanecer Em Analise\n");
                    printf("2 - Marcar como Confiavel\n");
                    printf("3 - Marcar como Suspeita\n");
                    printf("Escolha: ");
                    scanf("%d", &novaClassif);
 
                    if (novaClassif == 2 || novaClassif == 3) {
                        
                        Noticia* mover = (Noticia*) malloc(sizeof(Noticia));
                        if (mover != NULL) {
                            *mover       = p->info;        
                            mover->clasf = novaClassif;    
 
                            removerCabCau(&listaPendentes, p->info.id);
                            insereNoInicio(&listaVerificadas, mover);
                            printf("Noticia movida para verificadas.\n");
                        }
                    } else {
                        printf("Noticia mantida na lista de pendentes.\n");
                    }
                }
                break;
            }
 
            
            case 7: {
                int qtdEmAnalise  = retornaQtd(&listaPendentes);
                int qtdConfiaveis = retornaConfi(&listaVerificadas);
                int qtdSuspeitas  = retornaSusp(&listaVerificadas);
 
                printf("\n===========================================\n");
                printf("   QUANTIDADE DE NOTICIAS POR CATEGORIA    \n");
                printf("===========================================\n");
                printf("Em Analise : %d\n", qtdEmAnalise);
                printf("Confiaveis : %d\n", qtdConfiaveis);
                printf("Suspeitas  : %d\n", qtdSuspeitas);
                printf("===========================================\n");
                break;
            }
 
            
            case 8:
                printf("Encerrando o programa...\n");
 
                
                liberarCabCau(&listaPendentes);
                liberarEncadeada(&listaVerificadas);
                break;
 
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
 
    } while (opcao != 8);
 
    return 0;
}
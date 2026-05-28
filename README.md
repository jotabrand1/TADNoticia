# TAD Notícia em C 📰

Este repositório contém a implementação de um **Tipo Abstrato de Dados (TAD)** para o gerenciamento e classificação de notícias, desenvolvido na linguagem C. 

O projeto foi estruturado seguindo as melhores práticas de modularização, dividindo o código em arquivos de definição (`.h`), implementação das funções (`.c`) e o fluxo principal de teste (`main.c`).

## 🚀 Funcionalidades e Conceitos Aplicados

* **Encapsulamento (TAD):** Toda a estrutura da notícia e suas operações ficam restritas aos arquivos dinâmicos do TAD.
* **Alocação Dinâmica de Memória:** Uso estratégico de `malloc` e `free` para gerenciamento eficiente de memória da estrutura.
* **Garantia de ID Único:** Implementação de uma variável estática (`static int`) interna para controlar e autoincrementar o identificador único de cada notícia diretamente pelo programa.
* **Programação Defensiva:** Validação rigorosa de ponteiros nulos (`NULL`) para evitar falhas de segmentação (*Segmentation Faults*).
* **Estrutura de Classificação personalizada:** Uso de structs/enums para categorizar a confiabilidade da notícia (Em Análise, Confiável ou Suspeita).

## 📂 Estrutura do Projeto

* `Noticia.h`: Arquivo de cabeçalho com a definição das estruturas (`Noticia`, `Classificacao`) e os protótipos das funções obrigatórias.
* `Noticia.c`: Implementação da lógica das funções (`criarNoticia`, `imprimirNoticia`, `liberarNoticia`).
* `main.c`: Arquivo principal utilizado para realizar os testes de criação, exibição e liberação de memória.

## 💻 Como Compilar e Executar

Para compilar e rodar o projeto em sua máquina local via terminal (utilizando o GCC), siga os passos abaixo:

1. Clone o repositório ou baixe os arquivos.
2. Abra o terminal na pasta do projeto e compile os arquivos `.c` juntos:
   ```bash
   gcc main.c Noticia.c -o programa

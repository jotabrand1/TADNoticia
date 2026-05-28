#ifndef NOTICIA_H
#define NOTICIA_H

#define MAX 1000

typedef enum {
    EM_ANALISE = 1,
    CONFIAVEL = 2,
    SUSPEITA = 3
} Classificacao;

typedef struct noticia {
    int id;
    char data[11];
    char titulo[MAX];
    char conteudo[MAX];
    char fonte[MAX];
    Classificacao clasf;
} Noticia;

Noticia* criarNoticia();
void imprimirNoticia(Noticia* noticia);
void liberarNoticia(Noticia**noticia);

#endif
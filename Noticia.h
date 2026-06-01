#ifndef NOTICIA_H
#define NOTICIA_H
 
#define MAX 1000
 
/* Classificação possível de uma notícia */
typedef enum {
    EM_ANALISE = 1,
    CONFIAVEL  = 2,
    SUSPEITA   = 3
} Classificacao;
 
/* Estrutura que representa uma notícia */
typedef struct noticia {
    int           id;           /* Identificador único, gerenciado pelo programa */
    char          data[11];     /* Data de publicação no formato DD/MM/AAAA       */
    char          titulo[MAX];  /* Título da notícia                              */
    char          conteudo[MAX];/* Conteúdo da notícia                            */
    char          fonte[MAX];   /* Fonte da notícia                               */
    Classificacao clasf;        /* Classificação: EM_ANALISE, CONFIAVEL, SUSPEITA */
} Noticia;
 
/* Protótipos */
Noticia* criarNoticia();
void     imprimirNoticia(Noticia* noticia);
void     liberarNoticia(Noticia** noticia);
 
#endif /* NOTICIA_H */
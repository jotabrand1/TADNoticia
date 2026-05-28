#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noticia.h"


int main() {
    Noticia* noticia1 = criarNoticia();
    imprimirNoticia(noticia1);
    liberarNoticia(&noticia1);
    imprimirNoticia(noticia1);

    return 0;
}
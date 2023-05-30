#include <stdio.h>
#include <stdlib.h>
#include "Avl.h"
#include <string.h>
#include "altura.h"

int alturaArvore(Curso *raiz){
    int he = -1, hd = -1, h;

    if(raiz){
        he = alturaArvore(raiz->esq);
        hd = alturaArvore(raiz->dir);
        if(he > hd){
            h = he + 1;
        }else{
            h = hd + 1;
        }
    }else{
        h = -1;
    }
    return (h);
}
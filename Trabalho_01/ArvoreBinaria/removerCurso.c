#include <stdio.h>
#include <stdlib.h>
#include "../headers/curso.h"
#include <string.h>
#include "../headers/removerCurso.h"

void removerCurso(Curso **raiz, int codC) {
    Curso *aux;
    if (*raiz) {
        if ((*raiz)->codC == codC) {
            printf("%d\n", ehfolha(*raiz));
            if (ehfolha(*raiz)) {
                aux = *raiz;
                *raiz = NULL;
                free(aux);
            } else if (!((*raiz)->dir) || !((*raiz)->esq)) {
                Curso *endFilho;
                endFilho = enderecoFilho(*raiz);
                aux = *raiz;
                *raiz = endFilho;
                free(aux);
            }else{ // dois filhos
                Curso *aux, *filho_esq;
                aux = *raiz;
                filho_esq = (*raiz)->esq;
                esq_filh(&((*raiz)->esq), (*raiz)->dir);
                *raiz = filho_esq;
                free(aux);
            }
        }else if(codC < (*raiz)->codC)
            removerCurso(&((*raiz)->esq), codC);
        else
            removerCurso(&((*raiz)->dir), codC);
    }
}

void esq_filh(Curso **filho_recebe, Curso *filho_outro){
    if(*filho_recebe){
        esq_filh((&(*filho_recebe)->dir), filho_outro);
    }else{
        *filho_recebe = filho_outro;
    }
}

int ehfolha(Curso *raiz) { 
    return !(raiz->esq || raiz->dir);
}

Curso *enderecoFilho(Curso *raiz) {
    Curso *aux;
    if (raiz->dir)
        aux = raiz->dir;
    else 
        aux = raiz->esq;
    return aux;
}

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
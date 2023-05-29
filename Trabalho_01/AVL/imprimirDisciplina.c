#include <stdio.h>
#include <stdlib.h>
#include "../headers/Avl.h"
#include <string.h>
#include "../headers/imprimirDisciplina.h"

void imprimirDisciplina(Disciplina *raiz){
    if(raiz){
        printf("CodigoD: %d\nNome Dis: %s\nBlocos da disciplina: %d\nCarga Horaria: %d\n\n", raiz->codD, raiz->nome, raiz->qtdBDisciplina, raiz->cargHor);
    }
}

void imprimirDadosDisc(Disciplina *raiz){
    if(raiz){
        imprimirDadosDisc(raiz->esq);
        imprimirDisciplina(raiz);
        imprimirDadosDisc(raiz->dir);
    }
}

void imprimirDisciplinaCod(Disciplina *raiz, int cod){
    if(raiz){
        if(raiz->codD == cod)
            imprimirDisciplina(raiz);
        else if(cod < raiz->codD)
            imprimirDisciplinaCod(raiz->esq, cod);
        else
            imprimirDisciplinaCod(raiz->dir, cod);
    }
}
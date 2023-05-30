#include <stdio.h>
#include <stdlib.h>
#include "Avl.h"
#include "inserirDisciplina.h"
#include <string.h>

Disciplina *criarNoDisciplina(int codC, char nome[], int qtdBDisciplina, int cargHor){
    Disciplina *raiz;
    raiz = (Disciplina *) malloc(sizeof(Disciplina));
    raiz->codD = codC;
    strcpy(raiz->nome, nome);
    raiz->qtdBDisciplina = qtdBDisciplina;
    raiz->cargHor = cargHor;
    raiz->esq = raiz->dir = NULL;
    return raiz;
}

void inserirDisciplina(Disciplina **raiz, Disciplina *no){
    //fazer uma flag para saber se inseriu
    if(raiz){
        if(!(*raiz)){
            // if((*raiz).qtdBCurso > no->qtdBDisciplina && no->cargHor % (*raiz).semana == 0)
            *raiz = no;
        }else if((*no).codD < (**raiz).codD){
            inserirDisciplina(&((*raiz)->esq), no);
        }else{
            inserirDisciplina(&((*raiz)->dir),  no);
        }
    }
}
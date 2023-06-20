#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "curso.h"
#include "inserir.h"

// ----------------------------------- Cursos --------------------------------
Curso *criarCurso(){
    return NULL;
}

Curso *criarNoCurso(int codC, char nome[], int qtdBCurso, int semana){
    Curso *raiz;
    raiz = (Curso *) malloc(sizeof(Curso));
    raiz->codC = codC;
    raiz->disciplinas = NULL;
    strcpy(raiz->nome, nome);
    raiz->qtdBCurso = qtdBCurso;
    raiz->semana = semana;
    raiz->esq = raiz->dir = NULL;
    return raiz;
}

void inserirCurso(Curso **raiz, Curso *no){
    if(*raiz){
        if(no->codC < (**raiz).codC)
            inserirCurso(&((**raiz).esq), no);
        else if(no->codC > (**raiz).codC)
            inserirCurso(&((**raiz).dir), no);
    } else *raiz = no;
}

// ----------------------------------- Disciplinas --------------------------------

Disciplina *criarNoDisciplina(int codD, char nome[], int bloco, int cargHor){
    Disciplina *raiz;
    raiz = (Disciplina *) malloc(sizeof(Disciplina));
    raiz->codD = codD;
    strcpy(raiz->nome, nome);
    raiz->bloco = bloco;
    raiz->cargHor = cargHor;
    raiz->esq = raiz->dir = NULL;
    return raiz;
}

void auxiliarInserirDisc(Curso **curso, int codC, Disciplina *no){
    //fazer uma flag para saber se inseriu
    Curso *aux;
    aux = existeCurso(*curso, codC);

    if(aux){
        if(aux->qtdBCurso > no->bloco && no->cargHor % (aux)->semana == 0)
            inserirDisciplina(&(aux->disciplinas), no);
    }
}

void inserirDisciplina(Disciplina **raiz, Disciplina *no){
    if(!*raiz)
        *raiz = no;
    else if(no->codD < (*raiz)->codD)
        inserirDisciplina(&((*raiz)->esq), no);
    else if(no->codD > (*raiz)->codD)
        inserirDisciplina( &((*raiz)->dir), no);
}
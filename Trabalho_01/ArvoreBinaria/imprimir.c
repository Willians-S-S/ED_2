#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "curso.h"
#include "imprimir.h"


// --------------------------------Cursos --------------------------------

void imprimirCurso(Curso *no){
    if(no)
        printf("Codigo: %d\nNome: %s\nBlocos do Curso: %d\nSemanas: %d\n\n", no->codC, no->nome, no->qtdBCurso, no->semana);
}

// 1
void imprimirCursos(Curso *raiz){
    if(raiz){
        imprimirCursos(raiz->esq);
        imprimirCurso(raiz);
        imprimirCursos(raiz->dir);
    }
}

// 2
void imprimirDadosCurso(Curso *raiz, int cod){
    Curso *aux;
    aux = existeCurso(raiz, cod);
    if(aux){
        imprimirCurso(aux);
    }
}

// 3
void imprimirCursosQtdB(Curso *raiz, int qtdB){
    if(raiz){
        imprimirCursosQtdB(raiz->esq, qtdB); 
        if(qtdB == raiz->qtdBCurso){
            imprimirCurso(raiz);
        }
        imprimirCursosQtdB(raiz->dir, qtdB);
    }
}

// --------------------------------Disciplinas --------------------------------

void imprimirDisciplina(Disciplina *raiz){
    if(raiz)
        printf("CodigoD: %d\nNome Dis: %s\nBlocos da disciplina: %d\nCarga Horaria: %d\n\n", raiz->codD, raiz->nome, raiz->bloco, raiz->cargHor);
}

void imprimirDisciplinas(Disciplina *raiz){
    if(raiz){
        imprimirDisciplinas(raiz->esq);
        imprimirDisciplina(raiz);
        imprimirDisciplinas(raiz->dir);
    }
}

void imprimirDisciplinaCod(Disciplina *raiz, int codD){
    if(raiz){
        if(raiz->codD == codD)
            imprimirDisciplina(raiz);
        else if(codD < raiz->codD)
            imprimirDisciplinaCod(raiz->esq, codD);
        else
            imprimirDisciplinaCod(raiz->dir, codD);
    }
}


// 4
void imprimirDisciplinasCurso(Curso *raiz, int codC){
    Curso *aux;
    aux = existeCurso(raiz, codC);
    if(aux)
        imprimirDisciplinas(aux->disciplinas);
}

// 5
void imprimirDiscCurso(Curso *raiz, int codC, int codD){
    Curso *aux;
    aux = existeCurso(raiz, codC);
    if(aux)
        imprimirDisciplinaCod(aux->disciplinas, codD);
}


// 6
void imprimirDiscBloco(Curso *raiz, int codC, int bloco){
    Curso *aux;
    aux = existeCurso(raiz, codC);

    if(aux){
        discBloco(aux->disciplinas, bloco);
    }
}

// 6
void discBloco(Disciplina *raiz, int bloco){
    if(raiz){
        discBloco(raiz->esq, bloco);
        if(raiz->bloco == bloco)
            imprimirDisciplina(raiz);
        discBloco(raiz->dir, bloco);
    }
}

// (7) Imprimir todas as disciplinas de um determinado curso com a mesma carga horária, onde o código
// do curso e a carga horária devem ser informadas pelo usuário;
void imprimirDiscCursoHorario(Curso *raiz, int codC, int cargaHor){
    Curso *aux;
    aux = existeCurso(raiz, codC);
    if(aux)
        cargaHorDis(aux->disciplinas, cargaHor); 
}

// (7) Imprimir todas as disciplinas de um determinado curso com a mesma carga horária, onde o código
// do curso e a carga horária devem ser informadas pelo usuário;
void cargaHorDis(Disciplina *dis, int CargaHor){
    if(dis){
        cargaHorDis(dis->esq, CargaHor);
        if(dis->cargHor == CargaHor)
            imprimirDisciplina(dis);
        cargaHorDis(dis->dir, CargaHor);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include "../headers/curso.h"
#include <string.h>


Curso* existeCurso(Curso *raiz, int codC){
    Curso *aux;
    aux = NULL;
    if(raiz){
        if((*raiz).codC == codC){
            aux = raiz;
        }else if(codC < (*raiz).codC) aux = existeCurso((*raiz).esq, codC);
        else aux = existeCurso((*raiz).dir, codC);
    }
    return aux;
}






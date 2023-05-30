#include <stdio.h>
#include <stdlib.h>
#include "../headers/Avl.h"
#include "../headers/altura.h"
#include "../headers/inserirCurso.h"
#include <string.h>

Curso *criarCurso(){
    return NULL;
}

Curso *criarNoCurso(int codC, char nome[], int qtdBCurso, int semana){
    Curso *raiz;
    raiz = (Curso *)malloc(sizeof(Curso));
    raiz->codC = codC;
    raiz->disciplinas = NULL;
    strcpy(raiz->nome, nome);
    raiz->qtdBCurso = qtdBCurso;
    raiz->semana = semana;
    raiz->altura = 0;
    raiz->esq = raiz->dir = NULL;
    return raiz;
}


int inserirCurso(Curso **raiz, Curso *no){
    if (!(*raiz)){
        (*raiz) = no;
    }else if (no->codC < (**raiz).codC){
        inserirCurso(&((**raiz).esq), no);
    }else if (no->codC > (**raiz).codC){
        inserirCurso(&((**raiz).dir), no);
    }
    balancear(raiz);     
}

void balancear(Curso **raiz){
    if(*raiz){
        printf("teste1\n");
        int fator = fb(*raiz);

        if(fator < -1 && fb((*raiz)->dir) <= 0 )
            rotacaoEsqueda(raiz);
        else if(fator > 1 && fb((*raiz)->dir) >= 0 )
            rotacaoDireita(raiz);
        else if(fator < -1 && fb((*raiz)->dir) < 0 ){
            rotacaoEsqueda(raiz);
            rotacaoDireita(raiz);
        }else if(fator < -1 && fb((*raiz)->dir) < 0 ){
            rotacaoDireita(raiz);
            rotacaoEsqueda(raiz);
        }
        printf("teste2\n");
    }
}

int fb(Curso *no){
    return (alturaArvore(no->esq) - alturaArvore(no->dir));
}

void rotacaoEsqueda(Curso **raiz){
    Curso *filhoDireito, *filhoDofilho_direito;
    
    filhoDireito = (*raiz)->dir;
    filhoDofilho_direito = filhoDireito->esq;

    filhoDireito->esq = (*raiz);
    (*raiz)->dir = filhoDofilho_direito;

    (*raiz) = filhoDireito;

    (*raiz)->altura = alturaArvore(*raiz);
    filhoDofilho_direito->altura = alturaArvore(filhoDofilho_direito); 
}

void rotacaoDireita(Curso **raiz){
    Curso *filhoEsquerdo, *filhoDofilho_Esquerdo;
    
    filhoEsquerdo = (*raiz)->esq;
    filhoDofilho_Esquerdo = filhoEsquerdo->esq;

    filhoEsquerdo->esq = (*raiz);
    (*raiz)->esq = filhoDofilho_Esquerdo;

    (*raiz) = filhoEsquerdo;

    (*raiz)->altura = alturaArvore(*raiz);
    filhoDofilho_Esquerdo->altura = alturaArvore(filhoDofilho_Esquerdo); 
}

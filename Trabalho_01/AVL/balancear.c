#include <stdio.h>
#include "Avl.h"
#include "balancear.h"

// ------------------------------- Cursos -------------------------------
void balancear(Curso **raiz){
    if(*raiz){
        if(fb(*raiz) == 2){
            if(fb((*raiz)->esq) < 0)
                rotacaoEsquerda(&((*raiz)->esq));
            rotacaoDireita(raiz);
        }else if(fb(*raiz) == -2){
            if(fb((*raiz)->dir) > 0)
                rotacaoDireita(&((*raiz)->dir));
            rotacaoEsquerda(raiz);
        }
    }
}

int fb(Curso *no){
    int fator = 0;
    if(no)
        fator = (pegarAltura(no->esq) - pegarAltura(no->dir));
    return fator; 
}

void rotacaoEsquerda(Curso **raiz){
    Curso *aux;
    aux = (*raiz)->dir;
    (*raiz)->dir = aux->esq;
    aux->esq = (*raiz);
    (*raiz) = aux;

    atualizarAltura((*raiz)->esq);
    atualizarAltura((*raiz));

}

void rotacaoDireita(Curso **raiz){
    Curso *aux;
    
    aux = (*raiz)->esq;
    (*raiz)->esq = aux->dir;
    aux->dir = (*raiz);
    (*raiz) = aux;

    atualizarAltura((*raiz)->dir);
    atualizarAltura((*raiz));

}

int pegarAltura(Curso *raiz){
    int altura = -1;
    if(raiz)
        altura = raiz->altura;
    return altura;
}

void atualizarAltura(Curso *raiz){

    if(raiz){
        int alturaEsq, alturaDir;

        alturaEsq = pegarAltura(raiz->esq);
        alturaDir = pegarAltura(raiz->dir);

        raiz->altura = (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1;
    }
}


// ------------------------------- Disciplinas -------------------------------


int pegarAlturaDis(Disciplina *raiz){
    int altura = -1;
    if(raiz)
        altura = raiz->altura;
    return altura;
}

void atualizarAlturaDis(Disciplina *raiz){
    if(raiz){
        int h_esq, h_dir, altura;
        h_esq = pegarAlturaDis(raiz->esq);
        h_dir = pegarAlturaDis(raiz->dir);

        raiz->altura = (h_esq > h_dir ? h_esq : h_dir) + 1;
    }
}

int fbDis(Disciplina *raiz){
    int fator = 0;
    if(raiz)
        fator = (pegarAlturaDis(raiz->esq) - pegarAlturaDis(raiz->dir));
    return fator;
}

void balancearDis(Disciplina **raiz){
    if(*raiz){
        int fator = fbDis(*raiz);
        if(fator == 2){
            if(fbDis((*raiz)->esq) < 0)
                rotacaoEsqDis(&((*raiz)->esq));
            rotacaoDirDis(raiz);
        }else if(fator == -2){
            if(fbDis((*raiz)->dir) > 0)
                rotacaoDirDis(&((*raiz)->dir));
            rotacaoEsqDis(raiz);
        }
    }
}

void rotacaoEsqDis(Disciplina **raiz){
    Disciplina *aux;

    aux = (*raiz)->dir;
    (*raiz)->dir = aux->esq;
    aux->esq = *raiz;
    (*raiz) = aux;

    atualizarAlturaDis((*raiz)->esq);
    atualizarAlturaDis((*raiz));
}

void rotacaoDirDis(Disciplina **raiz){
    Disciplina *aux;
    aux = (*raiz)->esq;
    (*raiz)->esq = aux->dir;
    aux->dir = (*raiz);
    (*raiz) = aux;

    atualizarAlturaDis((*raiz)->esq);
    atualizarAlturaDis((*raiz));
}

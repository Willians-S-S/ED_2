#include <stdio.h>
#include <stdlib.h>
#include "../headers/Avl.h"
#include "../headers/inserirCurso.h"
#include "../headers/imprimirCurso.h"
#include "../headers/inserirDisciplina.h"
#include "../headers/imprimirDisciplina.h"
#include "../headers/removerCurso.h"



int main(){
    Curso *raiz, *aux;
    raiz = criarCurso();

    inserirCurso(&raiz, criarNoCurso(2002, "Sistemas", 8, 10));
    inserirCurso(&raiz, criarNoCurso(2000, "Nutrição", 10, 12));
    inserirCurso(&raiz, criarNoCurso(1900, "ADM", 10, 12));
    inserirCurso(&raiz, criarNoCurso(1950, "Matematica", 10, 12));
    inserirCurso(&raiz, criarNoCurso(2500, "Medicina", 10, 12));
    inserirCurso(&raiz, criarNoCurso(2550, "Biologia", 10, 12));
    inserirCurso(&raiz, criarNoCurso(2400, "Historia", 10, 12));
    inserirCurso(&raiz, criarNoCurso(2410, "Analise", 10, 12));
    inserirCurso(&raiz, criarNoCurso(2430, "Direito", 10, 12));
    inserirCurso(&raiz, criarNoCurso(2450, "Enfermagem", 10, 12));

    // Desenho da arvore
    // https://docs.google.com/spreadsheets/d/136U-07lrStLV6qE96hQp1BF0bdz2X90hQRP7Gl8jeCE/edit?usp=sharing

    aux = existeCurso(raiz,  2002);
    // if(aux) printf("Existe curso\n");
    // else printf("Não foi curso\n");
    // removerCurso(&raiz, 1900);
    inserirDisciplina( &aux->disciplinas, criarNoDisciplina(1, "ED_2", 1, 60));
    // imprimirCurso(raiz);
    inserirDisciplina(&aux->disciplinas, criarNoDisciplina(2, "ED_1", 1, 60));
    imprimirCurso(raiz);
    // printf("AAA\n");

    printf("Altura da arvore: %d\n", alturaArvore(raiz));

    return 0;
}
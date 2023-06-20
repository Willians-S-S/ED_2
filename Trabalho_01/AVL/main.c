#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Avl.h"
#include "inserir.h"
#include "imprimir.h"
#include "remover.h"
#include "balancear.h"

int main(){
    
    Curso *raiz, *aux;
    raiz = criarCurso();
    int op, cod, qtdBCurso, semana, bloco, cargaHor, codD;
    char nome[70];

    
    do{
        printf("1- Imserir Curso\t2- Inserir Disciplina\t3- Imprimir Cursos\t4- Imprimir dados de um dado Curso\n5- Imprimir Cursos pela quantidade de blocos\t6- Imprimir Disciplinas de um dado Curso\t7- Imprimir Disciplina de um dado Curso dada Disciplina\t8- Imprimir as Disciplinas dado o bloco\n9- Imprimir as Disciplinas de um dado Curso dado o horário\t10 - Remover Disciplina de um dado Curso e dado o código de Disciplina\t11- Remover Curso\t12- Altura da Árvore\n13- Altura de um nó específico\t14- Liberar Árvore de Curso\t15- Liberar Árvore de Disciplinas\n0- Sair\n");
        printf("Digite a opcao: ");
        scanf("%d", &op);

        switch (op){
        case 1:
            printf("Digite o nome do curso: ");
            // fgets(nome, sizeof(nome), stdin);
            scanf("%s", nome);
            printf("Digite o codigo do curso: ");
            scanf("%d", &cod);
            printf("Digite a quantidade de blocos do curso: ");
            scanf("%d", &qtdBCurso);
            printf("Digite a quantidade de semanas do curso: ");
            scanf("%d", &semana);

            inserirCurso(&raiz, criarNoCurso(cod, nome, qtdBCurso, semana));
            break;
        case 2:

            printf("Digite o nome da disciplina: ");
            scanf("%s", nome);
            printf("Digite o codigo da disciplina: ");
            scanf("%d", &cod);
            printf("Digite o bloco da disciplina: ");
            scanf("%d", &bloco);
            printf("Digite a carga horaria da disciplina: ");
            scanf("%d", &cargaHor);

            printf("Digite o codigo do curso: ");
            scanf("%d", &cod);

            auxiliarInserirDisc(&raiz, cod, criarNoDisciplina(cod, nome, bloco, cargaHor));
            break;
        case 3:
            // (1) Imprimir a árvore de cursos em ordem crescente pelo código do curso;
            imprimirCursos(raiz);
            break;
        case 4:
            // (2) Imprimir os dados de um curso dado o código do mesmo;
            printf("Digite o codigo do curso: ");
            scanf("%d", &cod);
            imprimirDadosCurso(raiz, cod);
            break;
        case 5:
            // (3) Imprimir todos os cursos com a mesma quantidade de blocos, onde o usuário informe a quantidade de blocos;
            printf("Digite a quantidade de bloco do curso: ");
            scanf("%d", &cod);
            imprimirCursosQtdB(raiz, qtdBCurso);
            break;
        case 6:
            // (4) Imprimir a árvore de disciplinas em ordem crescente pelo código das disciplinas dado o código do curso;
            printf("Digite o codigo do curso: ");
            scanf("%d", &cod);
            imprimirDisciplinasCurso(raiz, cod);
            break;
        case 7:
            // (5) Imprimir os dados de uma disciplina dado o código dela e do curso ao qual ela pertence;
            
            printf("Digite o codigo do curso: ");
            scanf("%d", &cod);
            printf("Digite o codigo da Disciplina: ");
            scanf("%d", &codD);
            imprimirDiscCurso(raiz, cod, codD);
            break;
        case 8:
            // (6) Imprimir as disciplinas de um determinado bloco de um curso, dado o bloco e o código do curso;
            printf("Digite o codigo do curso: ");
            scanf("%d", &cod);
            printf("Digite o bloco da Disciplina: ");
            scanf("%d", &bloco);
            imprimirDiscBloco(raiz, cod, bloco);
            break;
        case 9:
            // (7) Imprimir todas as disciplinas de um determinado curso com a mesma carga horária, onde o código do curso e a carga horária devem ser informadas pelo usuário;
            printf("Digite o codigo do curso: ");
            scanf("%d", &cod);
            printf("Digite a carga horaria das Disciplinas: ");
            scanf("%d", &cargaHor);
            imprimirDiscCursoHorario(raiz, cod, cargaHor);
            break;
        case 10:
            // (8) Excluir uma disciplina dado o código da disciplina e o código do curso;
            
            printf("Digite o codigo do curso: ");
            scanf("%d", &cod);
            printf("Digite o codigo da Disciplina: ");
            scanf("%d", &codD);

            auxRemoverDisc(&raiz, cod, codD);
            break;
        case 11:
            // (9) Excluir um curso dado o código do mesmo, desde que não tenha nenhuma disciplina cadastrada para aquele curso.
            printf("Digite o codigo do curso: ");
            scanf("%d", &cod);
            removerCurso(&raiz, cod);
            break;
        case 12:
            pegarAltura(raiz);
            break;
        case 13:
            printf("Digite o codigo do curso: ");
            scanf("%d", &cod);
            aux = existeCurso(raiz, cod);
            pegarAltura(aux);
            break;
        case 14:
            liberarArvoreCurso(&raiz);
            break;
        case 15:
            printf("Digite o codigo do curso: ");
            scanf("%d", &cod);
            aux = existeCurso(raiz, cod);
            liberarArvoreDisc(&aux->disciplinas);
            break;
        default:
            break;
        }
    }while(op != 0);

    return 0;
}



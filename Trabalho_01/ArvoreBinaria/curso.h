struct disciplina {
    int codD;
    char nome[50];
    int bloco;
    int cargHor;
    struct disciplina *esq, *dir;
};
typedef struct disciplina Disciplina;

struct curso {
    int codC;
    char nome[70];
    int qtdBCurso;
    int semana;
    Disciplina *disciplinas;
    struct curso *esq, *dir;
};
typedef struct curso Curso;

Curso *existeCurso(Curso *raiz, int codC);

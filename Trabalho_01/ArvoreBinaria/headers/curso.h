typedef struct Disciplina {
    int codD;
    char nome[50];
    int qtdBDisciplina;
    int cargHor;
    struct Disciplina *esq, *dir;
} Disciplina;

typedef struct Curso {
    int codC;
    char nome[70];
    int qtdBCurso;
    int semana;
    Disciplina *disciplinas;
    struct Curso *esq, *dir;
} Curso;



Curso* existeCurso(Curso *raiz, int codC);



// horária

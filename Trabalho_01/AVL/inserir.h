Curso *criarCurso();
void inserirCurso(Curso **raiz, Curso *no);
Curso *criarNoCurso(int codC, char nome[], int qtdBCurso, int semana); 

Disciplina *criarNoDisciplina(int codC, char nome[], int qtdBDisciplina, int cargHor);
void auxiliarInserirDisc(Curso **curso, int codC, Disciplina *no);
void inserirDisciplina(Disciplina **raiz, Disciplina *no);

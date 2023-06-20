void imprimirCurso(Curso *no);
void imprimirCursos(Curso *raiz); // imprimir todos os dados do curso
void imprimirDadosCurso(Curso *raiz, int cod); // imprimir somente os códigos
void imprimirCursosQtdB(Curso *raiz, int qtdB); // imprimir quantidade de cursos com mesma quantidade de blocos
void imprimirDisciplinasCurso(Curso *raiz, int codC);
void imprimirDiscCurso(Curso *raiz, int codC, int codD);
void imprimirDiscCursoHorario(Curso *raiz, int codC, int cargaHor); // imprimir todas as disciplinas com a mesma carga 
void imprimirDiscBloco(Curso *raiz, int codC, int bloco); // imprimir as disciplinas de um curso de um dado bloco

void discBloco(Disciplina *raiz, int bloco);
void cargaHorDis(Disciplina *dis, int CargaHor);

void imprimirDisciplina(Disciplina *raiz);
void imprimirDisciplinas(Disciplina *raiz);
void imprimirDisciplinaCod(Disciplina *raiz, int codD); // imprimir todos os dados da disciplina pelo codigo do curso
void imprimirDiscBloco(Curso *raiz, int codC, int bloco); // imprimir as disciplinas de um curso de um dado bloco

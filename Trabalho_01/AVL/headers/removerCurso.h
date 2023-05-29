void removerDisc(Curso **raiz, int codD, int codC); // remover disciplina do curso por código de ambos
void removerCurso(Curso **raiz, int codC); // remover curso (somente se estiver sem disciplinas)

int ehfolha(Curso *raiz);
Curso *enderecoFilho(Curso *raiz);

void esq_filh(Curso **filho_recebe, Curso *filho_outro);

int alturaArvore(Curso *raiz);
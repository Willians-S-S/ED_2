#include <stdio.h>
#include <stdlib.h>

typedef struct dados{
  int valor;
}Dados;

typedef struct arvore{
  Dados info;
  struct arvore *esq, *dir;
}Arvore;

Arvore *createNo(int num){
    Arvore *New = (Arvore*) malloc(sizeof(Arvore));
    New->info.valor = num;
    New->esq = NULL;
    New->dir = NULL;

    return New;
}

void insert(Arvore **raiz, Arvore *no){
    if(!(*raiz)){
        (*raiz) = no;
    }else if(no->info.valor < (*raiz)->info.valor){
        insert(&((*raiz)->esq), no);
    }else{
        insert(&((*raiz)->dir), no);
    }
}

void printar(Arvore *raiz){
    if(raiz != NULL){
        printf("%d\n", raiz->info.valor);
        printar (raiz->esq);
        printar (raiz->dir);
    }
}

void search(Arvore *raiz, int num, int *encontrou, Arvore **endereco){
    if(raiz){
        if(raiz->info.valor == num){
            *encontrou = 1;
            (*endereco) = raiz;
        }else if(num < raiz->info.valor){
            search(raiz->esq, num, encontrou, endereco);
        }else{
            search(raiz->dir, num, encontrou, endereco);
        }
    }
}

// Arvore *rumo(Arvore *raiz, int valor){
//     if(raiz->esq){
//         Arvore *aux = raiz->esq;

//         while(aux->dir) aux = aux->dir;
        
//         int valor_backup = aux->info.valor;
//         aux->info.valor = raiz->info.valor;
//         raiz->info.valor = valor_backup;
//     }else{
//         Arvore *aux = raiz->dir;

//         while(aux->esq) aux = aux->esq;
        
//         int valor_backup = aux->info.valor;
//         aux->info.valor = raiz->info.valor;
//         raiz->info.valor = valor_backup;
//     }

//     return raiz;
// }

void rumo_esq(Arvore *raiz){
    Arvore *aux = raiz->esq;
    while (aux->dir) aux = aux->dir;
    aux->dir = raiz->dir;
}

void rumo_dir(Arvore *raiz){
    Arvore *aux = raiz->dir;
    while (aux->esq) aux = aux->esq;
    aux->esq = raiz->esq;
}

void Remove(Arvore **raiz, int valor){
    if((*raiz)){
        if((*raiz)->info.valor == valor){
            Arvore *aux = (*raiz);

            if((*raiz)->esq && (*raiz)->dir){ // remove quando tem dois filhos
                rumo_esq((*raiz));
                (*raiz) = (*raiz)->esq; 
            }
            else if((*raiz)->esq || (*raiz)->dir){ // remove quando tem um filho
                if((*raiz)->esq){
                    rumo_esq((*raiz));
                    (*raiz) = (*raiz)->esq;
                }else{
                    rumo_dir((*raiz));
                    (*raiz) = (*raiz)->dir;
                }
            }else{ // libera a memória
                free(aux);
                aux = NULL;
            }

        }else if(valor < (*raiz)->info.valor){
            Remove(&((*raiz)->esq), valor);
        }else{
            Remove(&((*raiz)->dir), valor);
        }
    }
}

int main(void) {
    Arvore *raiz = NULL;
    
    insert(&raiz, createNo(50));
    insert(&raiz, createNo(40));
    insert(&raiz, createNo(60));
    insert(&raiz, createNo(45));
    insert(&raiz, createNo(100));

    printar(raiz);

    printf("\n");

    // int encontrou = 0;
    // Arvore *endereco = NULL;
    // search(raiz, 100, &encontrou, &endereco);

    // printf("Encotrou %d\n", encontrou);

    // printar(endereco);
    Remove(&raiz, 40);
    // printar(endereco);
    printar(raiz);
    return 0;
}
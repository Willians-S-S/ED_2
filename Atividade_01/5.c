#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa{
    int id;
    char nome[20];
    int anoNascimento;
    float altura;
};

struct lista{
    struct pessoa info;
    struct lista *prox;
};
typedef struct lista Lista;

Lista *inserir(Lista *lista, int id, char nome[], int anoNascimento, float altura){
    Lista *newNo = (Lista*) malloc (sizeof(Lista));

    newNo->info.id = id;
    strcpy(newNo->info.nome, nome);
    newNo->info.anoNascimento = anoNascimento;
    newNo->info.altura = altura;
    newNo->prox = NULL;

    if(!lista) return newNo;
    else if(lista->info.id > id){
        newNo->prox = lista;
        return newNo;
    }

    Lista *aux = lista;
    while(aux->prox && aux->prox->info.id < id) aux = aux->prox;

    newNo->prox = aux->prox;
    aux->prox = newNo;

    return lista;
}

void mostrar(Lista *lista){
    if(lista){
        printf("\nId: %d\nNome: %s\nNascimento: %d\nAltura %.2f\n\n", lista->info.id, lista->info.nome, lista->info.anoNascimento, lista->info.altura);
        mostrar(lista->prox);
    }
}

// pegar as pessoas mais velhar, 1° ir ate o final e ver qual é o mais velho, 2° voltar pegando as que tem a mesma idade
int maior_idade(Lista *lista, int maior_ida, char **nomes, int *i){
    if(lista){
        int idade = 2023 - lista->info.anoNascimento;
        if(idade > maior_ida) maior_ida = idade;
        maior_ida = maior_idade(lista->prox, maior_ida, nomes, i);
    }else if(!lista) return maior_ida;

    int idade = 2023 - lista->info.anoNascimento;
    if(idade == maior_ida){
        if(*i == 0){
            strcpy(nomes[0], lista->info.nome);
            *i = 1;
        }else{
            *i += 1;
            nomes = (char**) realloc(nomes, (*i) * sizeof(char*));
            nomes[*i - 1] = (char*) malloc(20 * sizeof(char));
            strcpy(nomes[*i - 1], lista->info.nome);
        }
    }
    return maior_ida;
}

void menor_maior_altura(Lista *lista, float *men, float *mai){
    if(lista){
        if(lista->info.altura > *mai) *mai = lista->info.altura;
        if(lista->info.altura < *men) *men = lista->info.altura;
        menor_maior_altura(lista->prox, men, mai);
    }
}

void altura_mediana(Lista *lista, int *qtd, float media){
    if(lista){
        if(media == lista->info.altura) ++*qtd;
        altura_mediana(lista->prox, qtd, media);
    }
}

void menor_que_40_maior_que_a_media(Lista *lista, int *qtd, float media){
    if(lista){
        int idade = 2023 - lista->info.anoNascimento;
        if(lista->info.altura > media && idade < 40){
            ++*qtd;
        }
        menor_que_40_maior_que_a_media(lista->prox, qtd, media);
    }
}

int main(){
    Lista *lista = NULL;

    // ----------------------- Inserir pessoas -----------------------
    lista = inserir(lista, 7, "Setimo", 2000, 1.00);
    lista = inserir(lista, 2, "Segundo", 2000, 1.84);
    lista = inserir(lista, 4, "Quarto", 2002, 1.84);
    lista = inserir(lista, 3, "Terceiro", 2002, 2.00);
    lista = inserir(lista, 1, "Primeiro", 2002, 2.00);
    lista = inserir(lista, 5, "Quinto", 2002, 2.68);
    mostrar(lista);

    // ----------------------- Encontrar pessoa(s) mais velha(s) -----------------------
    char **nomes;
    int i = 0;
    nomes = (char**) malloc(1 * sizeof(char*));
    nomes[0] = (char*) malloc(20 * sizeof(char));
    printf("Maior idade: %d\n", maior_idade(lista, 0, nomes, &i));
    for(int j = 0; j < i; j++){
        printf("Nome: %s\n", nomes[j]);
    }

    // ----------------------- Encontrar menor e maior altura -----------------------
    float menor = lista->info.altura, maior = lista->info.altura;
    menor_maior_altura(lista, &menor, &maior);
    printf("\n\nMenor: %.2f Maior %.2f\n", menor, maior);

    // ----------------------- Altura mediana -----------------------
    float media = (menor + maior) / 2;
    int qtd = 0;
    altura_mediana(lista, &qtd, media);
    printf("\nQuantidade de pessoas com altura mediana %d\n", qtd);

    // ----------------------- Numero de pessoas com menos de 40 e maior que a media -----------------------
    int qtd_maior_menor;
    menor_que_40_maior_que_a_media(lista, &qtd_maior_menor, media);
    printf("\nQuantidade de pessoas com altura mediana %d\n", qtd_maior_menor);

    return 0;
}



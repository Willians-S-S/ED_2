#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *maior_Nome(char nomes[][10], int i, int tam, char *maior){
    if(i < tam){
        maior = maior_Nome(nomes, ++i, tam, maior);
    }
    if(strlen(maior) < strlen(nomes[i])){
        return nomes[i];
    } else {
        return maior;
    }
}

void qtd_vogais(char nomes[][10], int i, int tam, int *qtd){
    if(i < tam){
        if(nomes[i][0] == 'a' || nomes[i][0] == 'e' || nomes[i][0] == 'i' || nomes[i][0] == 'o' || nomes[i][0] == 'u'){
            *qtd += 1;
        }
        qtd_vogais(nomes, ++i, tam, qtd);
    }
}

void Maiuscula_quatro(char nomes[][10], int i, int tam, char returnChar[][10], int j){
    if(i < tam){
        if(isupper(nomes[i][0]) && strlen(nomes[i]) >= 4){
            strcpy(returnChar[j], nomes[i]);
            ++j;
        }
        Maiuscula_quatro(nomes, ++i, tam, returnChar, j);
    }
}

int main(){
    char nomes[3][10], *maior, returnChar[3][10];
    int qtd = 0;

    for(int i = 0; i <3; i++){
        scanf("%s", &nomes[i]);
    }

    maior = nomes[0];

    printf("\nMaior string: %s \n\n",  maior_Nome(nomes, 0, 3, maior));

    qtd_vogais(nomes, 0, 3, &qtd);

    printf("Qtd de string que inicia com vogal: %d\n\n", qtd);

    Maiuscula_quatro(nomes, 0, 3, returnChar, 0); 

    for(int i = 0; i < 3; i++)
        printf("Nome maior que 4: %s\n", returnChar[i]);

    return 0;

}
#include <stdio.h>

void divisores(int vet[], int n, int cont, int i){
    if(cont > 0){
        if(n % cont == 0){
            vet[i] = cont;
            divisores(vet, n, --cont, ++i);
        }
        divisores(vet, n, --cont, i);
    }
}

int main(){

    int num;

    scanf("%d",&num);

    int vet[num];

    divisores(vet, num, 5, 0);

    for(int i=0; i<num; i++){
        printf("%d \n",vet[i]);
    }

    return 0;
}
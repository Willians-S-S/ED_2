#include <stdio.h>

void mdc_sem_pedencia(int a, int b, int c, int d, int cont, int *maximo){
    if(cont < a){
        if(a % cont == 0 && b % cont == 0 && c % cont == 0 && d % cont == 0){
            *maximo = cont;
        }
        mdc_sem_pedencia(a, b, c, d, ++cont, maximo);
    }
}

void mdc_com_pedencia(int a, int b, int c, int d, int cont, int *maximo){
    if(cont > 1){
        mdc_com_pedencia(a, b, c, d, --cont, maximo);
    }
    if(a % cont == 0 && b % cont == 0 && c % cont == 0 && d % cont == 0){
        *maximo = cont;
    }
}

int main(){
    int a = 12, b = 32, c = 24, d = 16, cont = 1, maximo = 0;

    // mdc_sem_pedencia(a, b, c, d, cont, &maximo);
    // printf("MDC sem pedencia: %d\n", maximo);

    mdc_com_pedencia(a, b, c, d, cont = a, &maximo);
    printf("MDC com pedencia: %d\n", maximo);

    return 0;
}
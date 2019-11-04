#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void exo1(){
    int saisie = -1;
    int max = saisie;

    int i = 0;
    int iMax = 0;

    while (saisie != 0){
        i++;

        scanf("%d", &saisie);
        printf("saisie : %d", saisie);
        if (saisie > max){
            max = saisie;
            iMax = i;
        }

    }
    printf("nombre : %d et indice : %d", max, iMax);
}

void divisionEuclidienne(int a, int b){

    int q = 0;
    int r = a;

    while (r >= b)
    {
        q += 1;
        r -= b;
    }
    printf("q = %d, r = %d \n", q, r);
}

void conversionTemp(int seconds){
    int minutes = seconds / 60;
    seconds = seconds % 60;
    int hours = minutes / 60;
    minutes = minutes % 60;
    int days = hours / 24;
    hours = hours % 24;
    printf("%d jours, %d h, %d min, %d sec \n", days, hours, minutes, seconds);
}


int puissance(int a, int b){
    if (b == 0) {
        return 1;
    }
    int result = a;

    for (size_t i = 1; i < b; i++){
        result *= a;
    }

    return result;
}

void effetMirroir(int x){
    int size = 1;
    int xnew = 0;

    while (x / puissance(10,size) >=1){
        size += 1;
    }
    
    printf("taille : %d \n", size);

    for (int i = size; i > 0; i--){
        xnew += (x / puissance(10,i-1)) * puissance(10,size-i);
        x = x % puissance(10,i-1);
        printf("xnew = %d et x =  %d \n", xnew, x);
    }
    
    printf("reverse : %d \n", xnew);
}


void main(int argc, char *argv[]){
    // exo1();

    divisionEuclidienne(10, 2);
    divisionEuclidienne(20, 7);

    conversionTemp(3672);

    int pow = puissance(2, 5);
    printf("puissance : %d \n", pow);

    effetMirroir(643);
}



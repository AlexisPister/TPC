#include <stdio.h>
#include <stdlib.h>


int *tableau() {
    static int* arrayz = NULL;
    int n = 3;
    int i = 0;

    while (i < n)
    {
        arrayz[i] = 1;
        i++;
    }
    

    return arrayz;
}

int value() {
    return 5;
}

void main(int argc, char *argv[]){
    int i;

    int *tab = tableau();
    int m = value();

    printf("tableau %d", tab[0]);
}
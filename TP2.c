#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void printTab(int *tab, int size) {
    printf("\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d, ", tab[i]);
    }
}

void swapArray( int *a, int *b, size_t n )
{
    for ( size_t i = 0; i < n; i++ )
    {
        int tmp = a[i];
        a[i] = b[i];
        b[i] = tmp;
    }
}


int *genArray(int taille){
    int upper = 50;
    int lower = 10;

    int *tab = malloc(sizeof(int) * taille);

    for (size_t i = 0; i < taille; i++) {
        tab[i] = (rand() % (upper - lower - 1)) + lower;
    }
    
    // printf("pointeur 1 : %p \n", tab);

    return tab;
}

void triBulle(int *tab, int size){
    int temp;
    int changement = 0;

    while (changement == 0){
        changement = 1;
        for (size_t i = 0; i < size - 1; i++)
        {
            if (tab[i] > tab[i+1]){
                changement = 0;
                temp = tab[i+1];
                tab[i+1] = tab[i];
                tab[i] = temp;
            }
        }
    }
}


int * fusion(int *tab1, int size1, int *tab2, int size2){
    int sizeFinal = size1 + size2;
    int *tabFinal = malloc(sizeof(int) * (sizeFinal));
    int i;
    int j = 0;
    int t = 0;

    if (tab2[size2 - 1] < tab1[size1 - 1]){
        printf("%p , %p \n", tab1, tab2);
        int* temp = tab1;
        tab1 = tab2;
        tab2 = temp;

        int temp2 = size1;
        size1 = size2;
        size2 = temp2;
        printf("%p , %p \n", tab1, tab2);
    }

    for (size_t i = 0; i < size1; i++){
        //printf("%d \n", t);
        if (tab1[i] < tab2[j]){
            tabFinal[t] = tab1[i];
        } else {
            tabFinal[t] = tab2[j];
            i -= 1;
            j += 1;
        }
        t += 1;
    }

    while (j < size2)
    {
        tabFinal[t] = tab2[j];
        t += 1;
        j += 1;
    }
    
    return tabFinal;
}

// Question 3
int rechercheEl(int* tab, int size, int value){
    int i = 0;
    int j = size - 1;

    while (i <= j){
        if (tab[(i + j)/2] == value) {
            return 1;
        } else if (tab[(i + j)/2] > value) {
            j = (i + j) / 2 - 1;
        } else {
            i = (i + j) / 2 + 1;
        }
    }

    return 0;
}


int ** genMat(int row, int col, int upper, int lower){
    int **mat = (int**) calloc(row, sizeof(int*));
    for (int i = 0; i < row; i++)
    {
        mat[i] = (int*) calloc(col, sizeof(int));
        for (int j = 0; j < col; j++)
        {
            mat[i][j] = (rand() % (upper - lower - 1)) + lower;
        }
        
    }
    return mat;
}

void displayMat(int **mat, int n, int m){
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int ** prodMat(int **mat1, int n1, int m1, int **mat2, int n2, int m2){
    printf("%d", mat2[3][1]);
    int **matFinal = (int**) calloc(n1, sizeof(int*));
    for (int i = 0; i < n1; i++)
    {
        matFinal[i] = (int*) calloc(m2, sizeof(int));
        for (int j = 0; j < m2; j++)
        {
            printf("\n %d , %d : %d", i, j, mat1[i][j]);
            matFinal[i][j] = 0;
            printf(" ok");
            for (int a = 0; a < m1; a++)
            {
                printf("\n a : %d", a);
                printf("\n mat1 : %d", mat1[i][a]);
                printf("\n mat2 : %d", mat2[a][j]);
                matFinal[i][j] += mat1[i][a] * mat2[a][j];
            }
        }
    }
}



int main(int argc, char *argv[]){
    srand(time(NULL));   // Initialization, should only be called once.

    int tableau[6] = {2,6,3,1,10,9};

    // printf("%lu \n", sizeof(tab) / sizeof(int));

    // printTab(tab, 6);
    // triBulle(tab, 6);
    // printTab(tab, 6);

    // Question 2
    // printf("generation \n");
    // int size1 = (rand() % (10 - 3 - 1)) + 3;
    // int size2 = (rand() % (10 - 3 - 1)) + 3;
    // int *tab1 = genArray(size1);
    // int *tab2 = genArray(size2);

    // printf("Tri \n");
    // triBulle(tab1, size1);
    // triBulle(tab2, size2);

    // printTab(tab1, size1);
    // printTab(tab2, size2);

    // printf("Fusion \n");
    // int *tabFusion = fusion(tab1, size1, tab2, size2);
    // printTab(tabFusion, size1 + size2);

    // int recherche = rechercheEl(tabFusion, size1 + size2, 12);
    // printf("element %d dans tableau : %d", 12, recherche);

    // free(tab2);
    // free(tab2);

    // Question 4 : matrices
    int **mat1 = genMat(3, 4, 10, 2);
    int **mat2 = genMat(4, 2, 10, 2);

    

    displayMat(mat1, 3, 4);
    displayMat(mat2, 4, 2);

    int **matfinal = prodMat(mat1, 3, 4, mat2, 4, 2);

    displayMat(matfinal, 3, 2);
    

}


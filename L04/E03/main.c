#include <stdio.h>
#define L_MAX 20

int main() {
    FILE *fp;
    char name[L_MAX];
    int M[L_MAX][L_MAX], nr, nc, i, j, dim, min, exit = 0, k, x, max, imax=0, jmax=0, somma;
    printf("Inserire nome file:");
    scanf("%s", name);
    fp=fopen(name, "r");

    if (fp == NULL) {
        printf("Errore apertura file.\n");
        return 1;
    }

    fscanf(fp,"%d %d", &nr, &nc);
    for (i=0; i<nr; i++) {
        for (j=0; j<nc; j++) {
            fscanf(fp,"%d", &M[i][j]);
        }
    }

    if (nr<nc)
        min = nr;
    else
        min = nc;

    while (!exit) {
        printf("Inserire dimensione sottomatrice (1<=dim<=%d):", min);
        scanf("%d", &dim);
        if (dim < 1 || dim > min) {
            exit = 1;
        }
        else {
            max = -1000;
            printf("Le sottomatrici di dimesione %d sono:\n", dim);
            for (i=0; i<nr && nr-i >= dim; i++) {
                for (j=0; j<nc && nc-j >= dim; j++) {
                    somma = 0;
                    for (k=0; k<dim; k++) {
                        for (x=0; x<dim; x++) {
                            printf("%d ", M[i+k][j+x]);
                            somma += M[i+k][j+x];
                        }
                        printf("\n");
                    }
                    printf("\n");
                    if (somma>max) {
                        max = somma;
                        imax = i;
                        jmax = j;
                    }
                }
            }
            printf("La sottomatrice con somma degli elementi massima (%d) e':\n", max);
            for (i=0; i<dim; i++) {
                for (j=0; j<dim; j++) {
                    printf("%d ", M[i+imax][j+jmax]);
                }
                printf("\n");
            }
            printf("\n");
        }
    }
    fclose(fp);
    return 0;
}
#include <stdio.h>
#define MAX 50
#define nero 1

void LeggiMatrice (FILE *fp, int M[][MAX], int *nr, int *nc);
int RiconosciRegione (int M[][MAX], int r, int c, int *b, int *h);

int main() {
    int M[MAX][MAX];
    int nr, nc, b, h;
    int i, j;
    char name[MAX];
    FILE *fp;
    printf("Inserire nome file input:");
    scanf("%s", name);
    if ((fp=fopen(name, "r"))==NULL) {
        printf("Errore apertura file input.\n");
        return -1;
    }
    LeggiMatrice(fp, M, &nr, &nc);
    for (i=0; i<nr; i++) {
        for(j=0; j<nc; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    for (i=0; i<nr; i++) {
        for (j=0; j<nc; j++) {
            if (RiconosciRegione(M, i, j, &b, &h)) {
                printf("Rettabgolo con estremo in (%d,%d), base %d e altezza %d.\n", i, j, b, h);
            }
        }
    }
    return 0;
}

void LeggiMatrice (FILE *fp, int M[][MAX], int *nr, int *nc) {
    int i, j;
    fscanf(fp,"%d%d", nr, nc);
    for (i=0; i<*nr; i++) {
        for (j=0; j<*nc; j++) {
            fscanf(fp, "%d", &M[i][j]);
        }
    }
}

int RiconosciRegione (int M[][MAX], int r, int c, int *b, int *h) {
    int i, j;
    if (M[r][c]==nero) {
        i=1;
        j=1;
        while (M[r][c+j]==nero) {
            j++;
        }
        while (M[r+i][c]==nero) {
            i++;
        }
        *b=j;
        *h=i;
        return 1;
    }
    else
        return 0;
}
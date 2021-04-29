#include <stdio.h>
#include <string.h>
#define MAXN 30

void riempiMatrice (int nr, int nc, FILE *fp, int M[MAXN][MAXN]);
void stampaMatrice (int nr, int nc, int M[MAXN][MAXN]);
void ruota (int selettore, int direzione, int indice, int posizioni, int M[MAXN][MAXN], int nr, int nc);

int main() {
    FILE *fp;
    char nome[20], selettore[20], direzione[20], scelta[100];
    int M[MAXN][MAXN];
    int nr, nc, indice, posizioni, sel, dir;

    printf("Inserire nome file:");
    gets(nome);

    if((fp=fopen(nome, "r")) == NULL) {
        printf("Errore nell'apertura del file di input.\n");
        return -1;
    }

    fscanf(fp, "%d%d", &nr, &nc);
    riempiMatrice(nr, nc, fp, M);
    stampaMatrice(nr, nc, M);

    printf("Inserire scelta:");
    scanf("%s%d%s%d", selettore, &indice, direzione, &posizioni);
    do {
        if (strcmp(selettore,"riga")==0) {
            sel = 1;
            if (strcmp(direzione, "destra")==0)
                dir = 1;
            else
                dir = -1;
        }
        else {
            sel = -1;
            if (strcmp(direzione, "su")==0)
                dir = 1;
            else
                dir = -1;
        }
        ruota(sel, dir, indice, posizioni, M, nr, nc);
        stampaMatrice(nr, nc, M);
        printf("Inserire scelta:");
        scanf("%s%d%s%d", selettore, &indice, direzione, &posizioni);
    } while (strcmp(selettore, "fine")!=0);

    return 0;
}

void riempiMatrice (int nr, int nc, FILE *fp, int M[MAXN][MAXN]) {
    int i, j;
    for (i=0; i<nr; i++) {
        for (j=0; j<nc; j++) {
            fscanf(fp, "%d", &M[i][j]);
        }
    }
}

void stampaMatrice (int nr, int nc, int M[MAXN][MAXN]) {
    int i, j;
    for (i=0; i<nr; i++) {
        for (j=0; j<nc; j++) {
            printf( "%d ", M[i][j]);
        }
        printf("\n");
    }
}

void ruota (int selettore, int direzione, int indice, int posizioni, int M[MAXN][MAXN], int nr, int nc) {
    int i, j, temp;

    switch (selettore) {
        case 1: {
            if (posizioni >= nc)
                posizioni = posizioni - nc;
            switch (direzione) {
                case -1: {
                    for (i = 0; i < posizioni; i++) {
                        for (j = 0; j <nc-1; j++) {
                            temp = M[indice - 1][j+1];
                            M[indice - 1][j+1] = M[indice - 1][j];
                            M[indice - 1][j] = temp;
                        }
                    }
                    return;
                }
                case 1: {
                    for (i = 0; i < posizioni; i++) {
                        for (j = nc - 1; j > 0; j--) {
                            temp = M[indice - 1][j - 1];
                            M[indice - 1][j - 1] = M[indice - 1][j];
                            M[indice - 1][j] = temp;
                        }
                    }
                    return;
                }
                default:
                    printf("Errore di inserimento.\n");
                    return;
            }
        }
        case -1: {
            if (posizioni >= nr)
                posizioni = posizioni - nr;
            switch (direzione) {
                case -1:{
                    for (i=0; i<posizioni; i++) {
                        for (j=nr-1; j>0; j--) {
                            temp = M[j-1][indice-1];
                            M[j-1][indice-1] = M[j][indice-1];
                            M[j][indice-1] = temp;
                        }
                    }
                    return;
                }
                case 1:{
                    for (i=0; i<posizioni; i++) {
                        for (j=0; j<nr-1; j++) {
                            temp = M[j+1][indice-1];
                            M[j+1][indice-1] = M[j][indice-1];
                            M[j][indice-1] = temp;
                        }
                    }
                    return;
                }
                default:
                    printf("Errore di inserimento.\n");
                    return;
            }
        }
        default:
            printf("Errore di inserimento.\n");
            return;
    }
}
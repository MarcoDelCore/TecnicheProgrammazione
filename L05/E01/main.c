#include <stdio.h>
#define MAX 20
#define input_file "../mat.txt"

typedef struct {
    int indice, punteggio;
} s_campionato;

void riempiMatrice (int nr, int nc, FILE *fp, int M[MAX][MAX]);
int cercaCapolista (s_campionato tab[], int nr, int nc, int M[MAX][MAX]);

int main() {
    int mat[MAX][MAX];
    int nr, nc, i, j;
    s_campionato tab[MAX];
    FILE *fp_fin;

    fp_fin = fopen(input_file, "r");

    fscanf(fp_fin, "%d%d", &nr, &nc);
    riempiMatrice(nr, nc, fp_fin, mat);

    for (i=0; i<nr; i++) {
        tab[i].indice = i;
        tab[i].punteggio = 0;
    }

    cercaCapolista(tab, nr, nc, mat);

    return 0;
}

void riempiMatrice (int nr, int nc, FILE *fp, int M[MAX][MAX]) {
    int i, j;
    for (i=0; i<nr; i++) {
        for (j=0; j<nc; j++) {
            fscanf(fp, "%d", &M[i][j]);
        }
    }
}

int cercaCapolista (s_campionato tab[], int nr, int nc, int M[MAX][MAX]) {
    int i, j, max, imax;

    for (i=0; i<nc; i++) {
        max=0;
        for (j=0; j<nr; j++) {
            tab[j].punteggio += M[j][i];
            if (tab[j].punteggio > max) {
                max = tab[j].punteggio;
                imax = tab[j].indice;
            }
        }
        printf("La squadra capolista alla giornata %d e' la squadra: %d.\n", i+1, imax+1);
    }
    return 0;
}
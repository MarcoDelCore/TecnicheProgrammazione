#include <stdio.h>
#define MAX 50
#define nero 1

void TrovaMax(int tab[MAX][MAX], int nr, int nc);

int main() {
    FILE *fp;
    char nome[MAX];
    int nr, nc, i, j;
    int M[MAX][MAX];

    printf("Inserire nome file input:");
    scanf("%s", nome);
    if ((fp = fopen(nome, "r")) == NULL) {
        printf("Errore aperture file input.\n");
        return -1;
    }
    fscanf(fp, "%d%d", &nr, &nc);
    for (i = 0; i < nr; i++) {
        for(j = 0; j < nc; j++) {
            fscanf(fp, "%d", &M[i][j]);
        }
    }
    TrovaMax(M, nr, nc);
    return 0;
}

void TrovaMax(int tab[MAX][MAX], int nr, int nc) {
    int i, j, k, x;
    int imax_B, jmax_B, imax_Al, jmax_Al, imax_Ar, jmax_Ar;
    int max_area=0, max_altezza=0, max_base=0;
    int l_base_B, l_altezza_B, l_base_Al, l_altezza_Al, l_base_Ar, l_altezza_Ar;

    for (i=0; i<nr; i++) {
        for (j=0; j<nc; j++) {
            if (tab[i][j] == nero) {
                k=1;
                x=1;
                while (tab[i][j+k]==nero) {
                    k++;
                }
                while (tab[i+x][j]==nero) {
                    x++;
                }
                if (k>max_base) {
                    max_base = k;
                    l_base_B = k;
                    l_altezza_B = x;
                    imax_B = i;
                    jmax_B = j;
                }

                if (x>max_altezza) {
                    max_altezza=x;
                    l_base_Al = k;
                    l_altezza_Al = x;
                    imax_Al = i;
                    jmax_Al = j;
                }

                if (x*k>max_area) {
                    l_base_Ar = k;
                    l_altezza_Ar = x;
                    max_area = l_base_Ar*l_altezza_Ar;
                    imax_Ar = i,
                    jmax_Ar = j;
                }
                j=j+k;
            }
        }
    }
    printf("Max Base: estr.sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n", imax_B, jmax_B, l_base_B, l_altezza_B, l_base_B*l_altezza_B);
    printf("Max Altezza: estr.sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n", imax_Al, jmax_Al, l_base_Al, l_altezza_Al, l_base_Al*l_altezza_Al);
    printf("Max Area: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n", imax_Ar, jmax_Ar, l_base_Ar, l_altezza_Ar, max_area);
}
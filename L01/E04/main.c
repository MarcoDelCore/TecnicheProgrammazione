#include <stdio.h>
#define P 3.14

int main() {
    int raggio, diametro, lato, diagonale, continua=1, check;
    float area_q, area_t;
    char scelta1, scelta2, scelta3;
    while (continua==1) {
        check=0;
        printf("Scegliere figura di cui calcolare l'area.\n");
        printf("Quadrato (Q) o Cerchio (C):");
        scanf("\n%c", &scelta1);
        printf("Scegliere misura da inserire.\n");
        switch (scelta1) {
            case 'Q':
                if (check==0){
                    printf("Lato (L) o Diagonale(D):");
                    scanf("\n%c", &scelta2);
                    switch (scelta2) {
                        case 'L':
                            printf("Inserisci lunghezza lato:");
                            scanf("%d", &lato);
                            area_q = lato * lato;
                            printf("Area quadrato = %.2f\n", area_q);
                            check=1;
                            break;

                        case 'D':
                            printf("Inserisci lunghezza diagonale:");
                            scanf("%d", &diagonale);
                            area_q = diagonale * diagonale / 2.0;
                            printf("Area del quadrato = %.2f\n", area_q);
                            check=1;
                            break;

                        default:
                            printf("Errore nella scelta.\n");
                            check=1;
                            break;
                    }
                }

            case 'C':
                if (check==0) {
                    printf("Raggio (R) o Diametro (D):");
                    scanf("\n%c", &scelta2);
                    switch (scelta2) {
                        case 'R':
                            printf("Inserisci lunghezza raggio:");
                            scanf("%d", &raggio);
                            area_t = P * raggio * raggio;
                            printf("Area del cerchio = %.2f\n", area_t);
                            check = 1;
                            break;

                        case 'D':
                            printf("Inserisci lunghezza diametro:");
                            scanf("%d", &diametro);
                            area_t = P * diametro * diametro / 4.0;
                            printf("Area del cerchio = %.2f\n", area_t);
                            check = 1;
                            break;

                        default:
                            printf("Errore nella scelta.\n");
                            check = 1;
                            break;
                    }
                }
            default:
                if (check==0)
                    printf("Errore nella scelta.\n");
                break;
        }

        printf("Continuare?\nSi'(S)/No(N):");
        scanf("\n%c", &scelta3);
        if (scelta3=='N')
            continua=0;
    }
    return 0;
}
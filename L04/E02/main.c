#include <stdio.h>
void ruota(int V[], int N, int P, int dir);

int main() {
    int maxN=30, V[maxN], i, P, dir, N;
    FILE *fp_in;
    char name[50];
    int temp;
    char scelta;

    do {
        printf("Inserire dimensione vettore (MAX 30):");
        scanf("%d", &N);
        if (N > 30 || N <= 0)
            printf("Dimensione non valida.\n");
    } while (N > 30 || N <= 0);

    printf("Inserire dati da tasiera (T) o da file (F)?");
    scanf("\n%c", &scelta);
    switch (scelta) {
        case 'T':
            for (i=0; i<N; i++) {
                printf("Inserire elemento %d del vettore:", i+1);
                scanf("%d", &V[i]);
            }
            break;
        case 'F': {
            printf("Inserire nome file:");
            scanf("\n%s", name);
            fp_in = fopen(name, "r");
            for (i=0; i<N; i++) {
                if (fscanf(fp_in, "%d", &temp) != EOF)
                    V[i] = temp;
            }
            break;
        }
        default:
            printf("Opzione non valida");
            return -1;
    }

    printf("Il vettore di partenza e':\n");
    for (i=0; i<N; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");

    printf("\nNumero posizioni:");
    scanf("%d", &P);
    while (P!=0) {
        if (P<N || P>0) {
            printf("Direzione (-1=destra, 1=sinistra):");
            scanf("%d", &dir);
            ruota(V, N, P, dir);
            printf("Il vettore ottenuto dalla rotazione e':\n");
            for (i=0; i<N; i++) {
                printf("%d ", V[i]);
            }
            printf("\n");
        }
        else
            printf("Valore posizioni non valido.\n");
        printf("\nNumero posizioni (0 per terminare):");
        scanf("%d", &P);
    }

    return 0;
}

void ruota(int V[], int N, int P, int dir) {
    int i, temp, j;
    switch (dir) {
        case 1:
          for (i=0; i<P; i++) {
              for (j=0; j<N-1; j++) {
                  temp = V[j+1];
                  V[j+1] = V[j];
                  V[j] = temp;
              }
          }
            break;
        case -1:
            for (i=0; i<P; i++) {
                for (j=N-1; j>0; j--) {
                    temp = V[j-1];
                    V[j-1] = V[j];
                    V[j] = temp;
                }
            }
            break;
        default:
            printf("Errore nella scelta della direzione.\n");
            break;
    }
}
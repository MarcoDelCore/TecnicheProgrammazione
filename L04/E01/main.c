#include <stdio.h>

int main() {
    int N=30, i, j=0, k;
    int V[N], sottovettori[N], max=0;
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
            FILE *fp_in;
            char name[50];
            int temp;
            printf("Inserire nome file:");
            scanf("\n%s", &name);
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

    for (i=0; i<N; i++) {
        if (i==0 || V[i-1]==0) {
            sottovettori[j] = i;
            j++;
        }
        if (V[i]==0 || i==N-1) {
            sottovettori[j] = i;
            if (sottovettori[j]-sottovettori[j-1]>max) {
                max = sottovettori[j] - sottovettori[j - 1];
            }
            j++;
        }
    }

    j=0;
    for (i=0; i<N; i++) {
        if (i == sottovettori[j] ) {
           if (sottovettori[j+1]-sottovettori[j]==max) {
               for (k = sottovettori[j]; k < sottovettori[j + 1]; k++) {
                   printf("%d ", V[k]);
               }
               printf("\n");
           }
           j += 2;
        }

    }

    return 0;
}

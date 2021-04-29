#include <stdio.h>
#define file_in "../numeri.txt"
#define file_out "../output.txt"

int main() {
    FILE *fp_in, *fp_out;
    int x1, x2, x3, max, min, n_scartati = 0, check;

    if ((fp_in = fopen(file_in, "r")) == NULL) {
        printf("Errore nell'aperture file input.\n");
        return 1;
    }
    if ((fp_out = fopen(file_out, "w")) == NULL) {
        printf("Errore nell'apertura file output.\n");
        return 2;
    }

    fscanf(fp_in, "%d %d", &x1, &x2);
    min = max = x1;
    if(x2>max)
        max=x2;
    if(x2<min)
        min=x2;
    do {
        fscanf(fp_in, "%d", &x3);
        check = 0;
        while (!check) {
            if ((x3!=x1+x2) && (x3!=x1-x2) && (x3!=x1*x2) && (x3!=x1/x2 && x2!=0)) {
                fscanf(fp_in, "%d", &x3);
                if (feof(fp_in))
                    check=1;
                n_scartati++;
            }
            else {
                check = 1;
                if (x3>max)
                    max=x3;
                if(x3<min)
                    min=x3;
            }
        }
        x1=x2;
        x2=x3;
    } while (!feof(fp_in));
    fprintf(fp_out, "Numero massimo: %d.\n", max);
    fprintf(fp_out, "Numero minimo: %d.\n", min);
    fprintf(fp_out, "Numeri scartati: %d.\n", n_scartati);
    fclose(fp_out);
    fclose(fp_in);
    return 0;
}


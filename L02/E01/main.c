#include <stdio.h>

int main() {
    int n1, n2, resto, max, min, mcd;
    printf("Inserire due numeri:");
    scanf("%d %d", &n1, &n2);
    if (n1 > n2) {
        max = n1;
        min = n2;
    }
    else {
        max = n2;
        min = n1;
    }
    do {
        resto = max % min;
        if (resto == 0)
            mcd = min;
        else {
            max = min;
            min = resto;
        }
    } while (resto != 0);
    printf("Risultato: MCD = %d", mcd);

    return 0;
}
#include <stdio.h>

int main() {
    float op1, op2, ris;
    char segno;
    printf("Scegliere operazione: +, -, * o /:");
    segno = getchar();
    printf("Inserire due numeri reali:");
    scanf("%f%f", &op1, &op2);

    switch (segno) {
        case '+':
            ris = op1 + op2;
            printf("%c %.2f", segno, ris);
            break;
        case '-':
            ris = op1 - op2;
            printf("%c %.2f", segno, ris);
            break;
        case '*':
            ris = op1*op2;
            printf("%c %.2f", segno, ris);
            break;
        case '/':
            if (op2 == 0) {
                printf("Operazione impossibile.");
                return 1;
            }
            else {
                ris = op1/op2;
                printf("%c %.2f", segno, ris);
                break;
            }
        default:
            printf("Errore nella selezione.");
            return 1;
    }
    return 0;
}

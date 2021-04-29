#include <stdio.h>

int main() {
    FILE *fp_read, *fp_write;
    float op1, op2, ris;
    char segno;
    if ((fp_read = fopen("../Operations.txt", "r")) == NULL){
        printf("Errore apertura file input.\n");
        return 1;
    }
    if((fp_write = fopen("../Results.txt", "w")) == NULL) {
        printf("Errore apertura file output.\n");
        return 2;
    }
    do {
        fscanf(fp_read, "%c%f%f\n", &segno, &op1, &op2);
        switch (segno) {
            case '+':
                ris = op1+op2;
                fprintf(fp_write, "%c %.2f\n", segno, ris);
                break;
            case '-':
                ris = op1-op2;
                fprintf(fp_write, "%c %.2f\n", segno, ris);
                break;
            case '*':
                ris = op1*op2;
                fprintf(fp_write, "%c %.2f\n", segno, ris);
                break;
            case '/':
                ris = op1/op2;
                fprintf(fp_write, "%c %.2f\n", segno, ris);
                break;
            default:
                fprintf(fp_write, "Impossibile eseguire operazione.\n");
                break;
        }
    } while (!feof(fp_read));
    fclose(fp_write);
    fclose(fp_read);
    return 0;
}
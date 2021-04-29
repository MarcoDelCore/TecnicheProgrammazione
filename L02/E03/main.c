#include <stdio.h>
int comprimi (FILE *fin,FILE *fout);
int decomprimi (FILE *fin, FILE *fout);

int main() {
    FILE *fp_in, *fp_out;
    char file1[50], file2[50], scelta;
    printf("Inserire nome file input:");
    gets(file1);
    printf("Inserire nome file output:");
    gets(file2);
    if((fp_in = fopen(file1, "r")) == NULL) {
        printf("Errore apertura file input.\n");
        return 1;
    }
    if ((fp_out = fopen(file2, "w")) == NULL) {
        printf("Errore apertura file output.\n");
        return 2;
    }

    printf("Comprimere(C) o Decomprimere(D)?");
    scelta = getchar();
    switch (scelta) {
        case 'C':
            return comprimi(fp_in, fp_out);
        case 'D':
            return decomprimi(fp_in, fp_out);
        default:
            printf("Errore nella scelta.");
    }

}


int comprimi( FILE *fin,FILE *fout) {
    char file_char, temp;
    int n_caratteri = 0, i, contatore, extra;
    file_char = fgetc(fin);
    fputc(file_char, fout);
    n_caratteri++;
    while (!feof(fin)) {
        contatore = 0;
        temp = fgetc(fin);
        if (!feof(fin)) {
            if (temp == file_char) {
                contatore++;
                while ((temp = fgetc(fin)) == file_char) {
                    contatore++;
                }
                if (contatore >= 2 && contatore <= 9) {
                    fprintf(fout, "$%d", contatore);
                    n_caratteri += 2;
                    if (!feof(fin)) {
                        fputc(temp, fout);
                        n_caratteri++;
                    }
                }
                else if (contatore >= 14) {
                    fprintf(fout, "$9%c$%d%c", file_char, (contatore-10), temp);
                    n_caratteri += 6;
                }
                else if (contatore > 9 && contatore < 14) {
                    fprintf(fout, "$9");
                    n_caratteri += 3;
                    extra = contatore - 9;
                    for (i = 0; i < extra; i++) {
                        fputc(file_char, fout);
                        n_caratteri++;
                    }
                    if (!feof(fin)) {
                        fputc(temp, fout);
                        n_caratteri++;
                    }
                }
                else {
                    fputc(file_char, fout);
                    fputc(temp, fout);
                    n_caratteri += 1;
                }
            }
            else {
                fputc(temp, fout);
                n_caratteri += 1;
            }
        }
        file_char = temp;
    }
    fclose(fin);
    fclose(fout);
    return n_caratteri;
}


int decomprimi(FILE *fin, FILE *fout) {
    char file_char, temp;
    int n_caratteri = 0, i, ripetizioni;
    file_char = fgetc(fin);
    fputc(file_char, fout);
    n_caratteri++;
    while(!feof(fin)) {
        temp = getc(fin);
        if (temp == '$') {
            temp = getc(fin);
            ripetizioni = temp - '0';
            for (i=0; i<ripetizioni; i++) {
                fputc(file_char, fout);
                n_caratteri++;
            }
        }
        else if (!feof(fin)) {
            fputc(temp, fout);
            n_caratteri++;
        }
        file_char = temp;
    }
    fclose(fin);
    fclose(fout);
    return n_caratteri;
}
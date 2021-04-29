#include <stdio.h>
#include <ctype.h>
int codifica (FILE *fin, FILE *fout);
int decodifica (FILE *fin, FILE *fout);

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

    printf("Codificare(C) o Decodificare(D)?");
    scelta = getchar();
    switch (scelta) {
        case 'C':
            return codifica(fp_in, fp_out);
        case 'D':
            return decodifica(fp_in, fp_out);
        default:
            printf("Errore nella scelta.");
    }
}

int codifica (FILE *fin, FILE *fout) {
    char file_char, precedente, k = '0', new_char, maiuscolo;
    int i, n_caratteri = 0, primo, num_new;
    file_char = fgetc(fin);
    primo = 1;
    while (!feof(fin)) {
        if (isdigit(file_char)) {
            new_char = file_char;
            for (i = 0; i < k - '0'; i++) {
                new_char++;
            }
            if ((new_char - '0') > 9) {
                new_char = ((new_char - '0') - 10) + '0';
            }

            k++;
        } else if (isalpha(file_char)) {
            if (isupper(file_char))
                maiuscolo = 1;
            else
                maiuscolo = 0;
            if (!primo) {
                if (isalpha(precedente)) {
                    new_char = file_char;
                    if (isupper(precedente)) {
                        for (i=0; i<((precedente-'0')-('A'-'0')); i++) {
                            new_char++;
                            num_new = new_char-'0';
                            if (maiuscolo) {
                                if ((new_char-'0') == ('Z'-'0')+1) {
                                    num_new -= 26;
                                    new_char = num_new+'0';
                                }
                            }
                            else {
                                if ((new_char-'0') == ('z'-'0')+1) {
                                    num_new -= 26;
                                    new_char = num_new + '0';
                                }
                            }
                        }
                    }
                    else {
                        for (i=0; i<((precedente-'0')-('a'-'0')); i++) {
                            new_char++;
                            num_new = new_char-'0';
                            if (maiuscolo) {
                                if ((new_char-'0') == ('Z'-'0')+1) {
                                    num_new -= 26;
                                    new_char = num_new + '0';
                                }
                            }
                            else {
                                if ((new_char - '0') == ('z' - '0') + 1) {
                                    num_new -= 26;
                                    new_char = num_new + '0';
                                }
                            }
                        }
                    }
                }
                else
                    new_char = file_char;
            }
            else
                new_char = file_char;
        } else
            new_char = file_char;

        fputc(new_char, fout);
        precedente = new_char;
        n_caratteri++;
        file_char = fgetc(fin);
        primo = 0;
    }
    fclose(fin);
    fclose(fout);
    return n_caratteri;
}

int decodifica (FILE *fin, FILE *fout) {
    char file_char, precedente, k = '0', new_char, maiuscolo;
    int i, n_caratteri = 0, primo, num_new;
    file_char = fgetc(fin);
    primo = 1;
    while (!feof(fin)) {
        if (isdigit(file_char)) {
            new_char = file_char;
            for (i = 0; i < k - '0'; i++) {
                new_char--;
            }
            if (new_char < '0') {
                new_char = ((new_char - '0') + 10) + '0';
            }

            k++;
        }
        else if (isalpha(file_char)) {
            new_char = file_char;
            if (isupper(file_char))
                maiuscolo = 1;
            else
                maiuscolo = 0;
            if (!primo) {
                if (isalpha(precedente)) {
                    new_char = file_char;
                    if (isupper(precedente)) {
                        for (i=0; i<((precedente-'0')-('A'-'0')); i++) {
                            new_char--;
                            num_new = new_char-'0';
                            if (maiuscolo) {
                                if ((new_char-'0') == ('A'-'0')-1) {
                                    num_new += 26;
                                    new_char = num_new+'0';
                                }
                            }
                            else {
                                if ((new_char-'0') == ('a'-'0')-1) {
                                    num_new += 26;
                                    new_char = num_new + '0';
                                }
                            }
                        }
                    }
                    else {
                        for (i=0; i<((precedente-'0')-('a'-'0')); i++) {
                            new_char--;
                            num_new = new_char-'0';
                            if (maiuscolo) {
                                if ((new_char-'0') == ('A'-'0')-1) {
                                    num_new += 26;
                                    new_char = num_new + '0';
                                }
                            }
                            else {
                                if ((new_char - '0') == ('a' - '0') - 1) {
                                    num_new += 26;
                                    new_char = num_new + '0';
                                }
                            }
                        }
                    }
                }
                else
                    new_char = file_char;
            }

        }
        else {
            new_char = file_char;
        }
        fputc(new_char, fout);
        precedente = file_char;
        n_caratteri++;
        file_char = fgetc(fin);
        primo = 0;
    }
    fclose(fin);
    fclose(fout);
    return n_caratteri;
}

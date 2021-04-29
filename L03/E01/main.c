#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define filein "../input.txt"
#define fileout "../testo.txt"

int main() {
    FILE *file_in, *file_out;
    char line[80];
    int i, j, maiuscolo = 0, contatore, spazi, MAX;


    if ((file_in = fopen(filein, "r")) == NULL ) {
        printf("Errore apertura file input.");
        return 1;
    }
    if ((file_out = fopen(fileout, "w")) == NULL ) {
        printf("Errore apertura file output.");
        return 2;
    }

    do {

        contatore = 0;
        spazi = 0;
        fgets(line, 50, file_in);
        MAX = strlen(line);

        for (i = 0; i < MAX && line[i] != '\n'; i++) {

            if (isdigit(line[i])) {
                fputc('*', file_out);
            } else if (isalpha(line[i])) {
                if ((maiuscolo == 1) && islower(line[i])) {
                    fputc(toupper(line[i]), file_out);
                } else {
                    fputc(line[i], file_out);
                }
                maiuscolo = 0;
            } else if (ispunct(line[i])) {
                if ((line[i] == '.') || (line[i] == '!') || (line[i]) == '?') {
                    maiuscolo = 1;
                }
                fputc(line[i], file_out);
                if (!isspace(line[i + 1])) {
                    fputc(' ', file_out);
                    spazi++;
                }
            } else {
                fputc(line[i], file_out);
            }

            if (contatore+spazi == 25) {
                fprintf(file_out, "| c:%d\n", contatore);
                contatore = 0;
                spazi = 0;
            } else {
                contatore++;
                if (contatore + spazi == 25) {
                    fprintf(file_out, "| c:%d\n", contatore);
                    contatore = 0;
                    spazi = 0;
                }
            }

        }

        if (contatore + spazi != 0) {
            for (j = 0; j < (25 - (contatore+spazi)); j++) {
                fputc(' ', file_out);
            }
        }

        fprintf(file_out,"| c:%d\n", contatore);
    } while (!feof(file_in));

    fclose(file_in);
    fclose(file_out);
    return 0;

}
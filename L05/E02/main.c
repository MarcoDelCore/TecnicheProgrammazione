#include <stdio.h>
#include <string.h>

#define sorgente "../sorgente.txt"
#define dizionario "../dizionario.txt"
#define ricodificato "../ricodificato.txt"

typedef struct{
    char codice[20];
    char parola[20];
} s_dizionario;

void leggiDizionario (FILE *f_diz,s_dizionario diz[], int num);
void ricodificaRiga(char riga[], s_dizionario diz[], int codifiche, FILE *fout);

int main() {
    FILE *f_sor, *f_diz, *f_ric;
    int codifiche;
    s_dizionario diz[30];
    char riga[200];

    if ((f_sor = fopen(sorgente, "r")) == NULL) {
        printf("Errore apertura file sorgente.txt.\n");
        return 1;
    }
    if ((f_diz = fopen(dizionario, "r"))==NULL) {
        printf("Errore apertura file dizionario.txt");
        return 2;
    }
    if ((f_ric = fopen(ricodificato, "w")) == NULL) {
        printf("Errore apertura file ricodificato.txt");
        return 3;
    }

    fscanf(f_diz, "%d", &codifiche);
    leggiDizionario(f_diz, diz, codifiche);
    fclose(f_diz);

    do {
        fgets(riga, 200, f_sor);
        ricodificaRiga(riga, diz, codifiche, f_ric);
    } while (!feof(f_sor));
    fclose(f_sor);
    fclose(f_ric);

    return 0;
}

void leggiDizionario (FILE *f_diz,s_dizionario diz[], int num) {
    int i;
    for (i=0; i<num; i++) {
        fscanf(f_diz, "%s%s", diz[i].codice, diz[i].parola);
    }
}

void ricodificaRiga(char riga[], s_dizionario diz[], int codifiche, FILE *fout) {
    int i, j, k, x, precedente=0, trovato;
    for (i=0; i<strlen(riga); i++) {
        trovato = 0;
        for (j=0; j<codifiche && !trovato; j++) {
            k = 0;
            while (riga[i+k] == diz[j].parola[k] && riga[i+k] != '\0') {
                k++;
            }
            if (k == strlen(diz[j].parola)) {
                for (x=precedente; x<i; x++) {
                    fprintf(fout, "%c", riga[x]);
                }
                fprintf(fout, "%s", diz[j].codice);
                precedente = i+k;
                trovato = 1;
            }
        }
        i = i+k;
    }
    for (i=precedente; i< strlen(riga); i++) {
        fprintf(fout, "%c", riga[i]);
    }
}
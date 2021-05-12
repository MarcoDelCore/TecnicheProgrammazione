#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define sequenze "../sequenze.txt"
#define testo "../testo.txt"

typedef struct {
    char sequenza[6];
    char parola[10][26];
    int posizione[10];
    int occorrenze;
}s_sequenze;

void trovaCorrispondenze(char parola[201], int ns, s_sequenze tab[], int pos);
void stampaOccorrenze (int ns, s_sequenze tab[]);

int main() {
    FILE *fp_seq, *fp_in;
    int i, j, k, ns, pos;
    char parola[26], riga[201], controllo[40][26];
    s_sequenze tab[20];

    if ((fp_seq=fopen(sequenze,"r"))==NULL) {
        printf("Errore apertura file sequenze.txt\n");
        return 1;
    }
    if ((fp_in=fopen(testo, "r"))==NULL) {
        printf("Errore apertura file testo.txt\n");
        return 2;
    }

    for (i=0; i<20; i++) {
        tab[i].occorrenze=0;
    }

    fscanf(fp_seq, "%d", &ns);
    for (i=0; i<ns; i++) {
        fscanf(fp_seq, "%s", tab[i].sequenza);
    }
    pos=0;
    do {
        fgets(riga, 201, fp_in);
        for (i=0; i< strlen(riga); i++) {
            j=0;
            while (!isspace(riga[i+j]) && !ispunct(riga[i+j])) {
                parola[j] = riga[i+j];
                j++;
            }
            if (j>0) {
                parola[j] = '\0';
                strcpy(controllo[pos], parola);
                pos++;
                trovaCorrispondenze(parola, ns, tab, pos);
            }
            i=i+j;
        }
    } while (!feof(fp_in));

    stampaOccorrenze(ns, tab);

    fclose(fp_in);
    fclose(fp_seq);
    return 0;
}

void trovaCorrispondenze(char parola[26], int ns, s_sequenze tab[], int pos) {
    int i, j, k, trovato;
    for (i=0; i< strlen(parola); i++) {
        trovato=0;
        for (j=0; j<ns && !trovato; j++) {
            k=0;
            while(tolower(parola[i+k]) == tolower(tab[j].sequenza[k]) && parola[i+k]!='\0') {
                k++;
            }
            if (k==strlen(tab[j].sequenza)) {
                if (tab[j].occorrenze < 10) {
                    strcpy(tab[j].parola[tab[j].occorrenze], parola);
                    tab[j].posizione[tab[j].occorrenze] = pos;
                    tab[j].occorrenze++;
                    trovato = 1;
                    i=i+k;
                }
            }
        }
    }

}

void stampaOccorrenze (int ns, s_sequenze tab[]) {
    int i, j;
    for (i=0; i<ns; i++) {
        if (tab[i].occorrenze != 0) {
            printf("La seuqenza \"%s\" e' contenuta in:\n", tab[i].sequenza);
            for (j = 0; j < tab[i].occorrenze-1; j++) {
                printf("%d. %s (parola in posizione %d nel testo);\n", j+1, tab[i].parola[j], tab[i].posizione[j]);
            }
            printf("%d. %s (parola in posizione %d nel testo).\n", j+1, tab[i].parola[j], tab[i].posizione[j]);
        }
        else {
            printf("La sequenza \"%s\" non e' contenuta in nessuna parola del testo.\n", tab[i].sequenza);
        }
        printf("\n");
    }
}
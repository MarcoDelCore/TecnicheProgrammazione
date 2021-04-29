#include <stdio.h>
#include <string.h>
#define MAXN 30

typedef struct {
    char codice[MAXN];
    char partenza[MAXN];
    char destinazione[MAXN];
    char data[MAXN];
    char ora_p [MAXN];
    char ora_a[MAXN];
    int ritardo;
} s_log;

typedef enum {
    r_date, r_partenza, r_capolinea, r_ritardo, r_ritardo_tot, r_fine, r_err
} comando_e;

comando_e leggiComando(void);
void menuParola(s_log tab[], int nr, int comando);
void stampaInfoDate (s_log tab[], int nr, int comando, char data_1[MAXN], char data_2[MAXN]);
void stampaInfoFermate (s_log tab[], int nr, int comando, char fermata[MAXN]);
void stampaInfoRitardo (s_log tab[], int nr, char codice[MAXN]);
void stampa(s_log tab[], int i);

int main() {
    FILE *fp;
    char name[MAXN], buff[100];
    int nr, i;
    s_log tab[1000];
    comando_e comando;

    printf("Inserire nome file log:");
    scanf("%s", name);

    if((fp=fopen(name, "r"))==NULL) {
        printf("Errore apertura file log.\n");
        return -1;
    }

    fscanf(fp, "%d", &nr);
    for (i=0; i<nr; i++) {
        fscanf(fp, "%s %s %s %s %s %s %d", tab[i].codice, tab[i].partenza,
               tab[i].destinazione, tab[i].data, tab[i].ora_p, tab[i].ora_a, &tab[i].ritardo);
    }

    comando = leggiComando();
    do {
        if (comando==r_err) {
            printf("Errore inserimento comando.\n");
            gets(buff);
        }
        else
            menuParola(tab, nr, comando);
        comando = leggiComando();
    } while (comando!=r_fine);
    return 0;
}

comando_e leggiComando(void) {
    char comando[MAXN];
    comando_e c;
    char tabella[r_err][15] = {
            "date", "partenza", "capolinea", "ritardo", "ritardo_tot", "fine"
    };
    printf("Inserire comando:");
    scanf("%s", comando);
    c=r_date;
    while (c<r_err && strcmp(comando,tabella[c])!=0)
        c++;
    return c;
}

 void menuParola(s_log tab[], int nr, int comando) {
    char data_2[MAXN], data_1[MAXN], fermata[MAXN], codice[MAXN];
     switch (comando) {
         case r_date: case r_ritardo: {
             scanf("%s%s", data_1, data_2);
             stampaInfoDate(tab, nr, comando, data_1, data_2);
             return;
         }
         case r_partenza: case r_capolinea: {
             scanf("%s", fermata);
             stampaInfoFermate(tab, nr, comando, fermata);
             return;
         }
         case r_ritardo_tot: {
             scanf("%s", codice);
             stampaInfoRitardo(tab, nr, codice);
             return;
         }
     }
}

void stampaInfoDate (s_log tab[], int nr, int comando, char data_1[MAXN], char data_2[MAXN]) {
    int i;
    char max[MAXN], min[MAXN];
    if (strcmp(data_1,data_2)<0) {
        strcpy(min, data_1);
        strcpy(max, data_2);
    }
    else {
        strcpy(min, data_2);
        strcpy(max, data_1);
    }
    switch (comando) {
        case r_date:
            printf("Le corse partite nell'intervallo di date %s-%s sono:\n", data_1, data_2);
            break;
        case r_ritardo:
            printf("Le corse che hanno raggiunto la destinazione in ritardo nell'intervallo "
                   "di date %s-%s sono:\n", data_1, data_2);
            break;
    }
    for (i=0; i<nr; i++) {
        if(strcmp(tab[i].data,min)>=0 && strcmp(tab[i].data,max)<=0) {
            if (comando==r_ritardo && tab[i].ritardo!=0) {
                stampa(tab, i);
            }
            else
                stampa(tab, i);
        }
    }
    printf("\n");
}

void stampaInfoFermate (s_log tab[], int nr, int comando, char fermata[MAXN]) {
    int i;
    switch (comando) {
        case r_partenza:
            printf("Le corse partite dalla fermata %s sono:\n", fermata);
            break;
        case r_capolinea:
            printf("Le corse con destinazione %s sono:\n", fermata);
            break;
    }
    for (i=0; i<nr; i++) {
        if (comando==r_partenza && strcmp(tab[i].partenza, fermata)==0)
            stampa(tab, i);
        else if (comando==r_capolinea && strcmp(tab[i].destinazione,fermata)==0)
            stampa(tab, i);
    }
    printf("\n");
}

void stampaInfoRitardo (s_log tab[], int nr, char codice[MAXN]) {
    int i, ritardo=0;
    for (i=0; i<nr; i++) {
        if (strcmp(tab[i].codice,codice)==0)
            ritardo += tab[i].ritardo;
    }
    printf("Il ritardo accumulato dalle corde identificate dal codice "
           "di tratta %s e' di %d minuti.\n", codice, ritardo);
    printf("\n");
}

void stampa(s_log tab[], int i) {
    printf("%s %s %s %s %s %s\n", tab[i].codice, tab[i].partenza,
           tab[i].destinazione, tab[i].data, tab[i].ora_p, tab[i].ora_a);
}
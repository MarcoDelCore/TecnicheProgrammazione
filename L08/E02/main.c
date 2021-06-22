#include <stdio.h>

void stampaCodifica(void *p, int size, int BigEndian);
int isBigEndian();
void binaryRepresentation(unsigned char t);

int main() {
    int ai;
    float af;
    double ad;

    int BigEndian = isBigEndian();



    printf(BigEndian  ? "Big endian\n":"Little endian\n");

    printf("Inserire numero:");
    scanf("%f", &af);
    ad = (double)af;
    ai = -1;

    printf("Dimensione float %f: %d\n",af, sizeof(af));
    printf("Dimensione double %f: %d\n",ad, sizeof(ad));

    stampaCodifica((void *)(&af), sizeof(af), BigEndian);
    printf("\n");
    stampaCodifica((void *)(&ad), sizeof(ad), BigEndian);
    printf("\n");
    stampaCodifica((void *)(&ai), sizeof(ai), BigEndian);
    return 0;
}

void stampaCodifica(void *p, int size, int BigEndian) {
    int start = 0, end = size, dir=1, j=0, i;
     char *c;
     char tmp[size];
    if(!BigEndian){
        start = size - 1;
        end = 0;
        dir = -1;
    }
    for (i = start; i < end; i += dir) {
        c = (char*)(p+i);
        tmp[j] = *c;
        j++;
    }
    for (i = 0; i < size; i++)  {
        binaryRepresentation(tmp[i]);
    }

}

int isBigEndian() {
    int bigEndian=0;
    int test=1;
    char *p;
    p=(char *)(&test);
    for(int i = 0 ; i < 4; i++) {
        p++;
    }
    if (*p == 1)
        bigEndian=1;
    return bigEndian;
}

void binaryRepresentation(unsigned char t) {
    int value = (unsigned int)t;
    int bitValue[8];
    int i;
    for (i=0; i<8; i++) {
        bitValue[i]=0;
    }
    i = 7;
    while(value!=0) {
        bitValue[i]=value%2;
        value = value/2;
        i--;
    }
    for (i=0; i<8; i++) {
        printf("%d", bitValue[i]);
    }
    //printf("\n");
}

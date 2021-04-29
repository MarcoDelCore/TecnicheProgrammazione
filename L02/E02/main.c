#include <stdio.h>

int main(){
    int N, n1=0, n2=1, n3, i;
    printf("Inserire numero termini serie di Fibionacci:");
    scanf("%d", &N);
    printf("%d %d ", n1, n2);
    for (i=0; i<N-2; i++) {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        printf("%d ", n3);
    }
    return 0;
}
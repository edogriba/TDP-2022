#include <stdio.h>

#define DIM 3
void sottoSequenze (int V[], int N);
int main() {
    const int N=30;
    int V[N], k;
    char x=' ';
    int i = 0, j , true=1;
    printf("Digitare una serie di numeri che andranno ad occupare gli elementi di un vettore\n");
    while (true) {
        scanf("%d%c", &V[i], &x);
        if (x=='\n') {
            true =0;
        }
        i++;
    }
    sottoSequenze(V, DIM);

    return 0;
}
void sottoSequenze (int V[], int N) {
    int i, j, k, flag, counter, index;
    char subvector_data[2];
    for (i=0; i<N; i++) {
        counter = 0;
        index = counter;
        if (V[i] != 0) {
            counter++;
        }
        else {
            subvector_data[0]
            index = counter;
            counter = 0;
        }

    }
}
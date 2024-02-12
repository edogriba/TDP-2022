#include <stdio.h>
#define MAX_SUBVECTOR 15

/* Algoritmo
 * Il main si occupa solo di creare con input da terminale il vettore di numeri che verrà poi manipolato dalla funzione sottoSequenze()
 * La funzione sottoSequenze() chiama una matrice dove ogni riga equivale ad un vettore
 * la prima casella indica l'indice dell'elemento iniziale del sottovettore e la seconda l'indice dell'elemento finale
 * Dopodiché con un ciclo for scandisco la matrice facendo le differenze tra gli indici contenuti nelle due caselle per stabilire la lunghezza massima dei sottovettori
 * Dopodiché con un ulteriore ciclo for sulla matrice vedo se la differenza tra i due indici corrisponde al massimo registrato
 * Se cosi è, procedo a stampare il sottovettore avendo a disposizione gli apici indici d'inizio e fine all'interno del vettore iniziale
 */

int lunghezza_vettore = 0;

void sottoSequenze (int V[], int N);
int main() {
    const int N=30;
    int V[N];
    char x=' ';
    int true=1;
    printf("Digitare una serie di numeri che andranno ad occupare gli elementi di un vettore\n");
    while (true && lunghezza_vettore <= 30) {
        scanf("%d%c", &V[lunghezza_vettore], &x);
        if (x=='\n') {
            true =0;
        }
        lunghezza_vettore++;
    }
    sottoSequenze(V, N);

    return 0;
}

void sottoSequenze (int V[], int N) {
    int i, j=0, first=1, counter, max=0, length, f;
    int subvector_data[MAX_SUBVECTOR][2];
    subvector_data[3][1] = 3;
    counter = 0;
    for (i=0; i<lunghezza_vettore; i++) {
        if (first && V[i] != 0) {
            subvector_data[j][0] = i;
            first=0;
        }
        else {
            if (V[i] != 0) {
                counter++;
                subvector_data[j][1] = i;
            } else {
                if (counter != 0) {
                    j++;
                    subvector_data[j][0] = i+1;
                }
            }
        }
    }
    for (i=0; i<=j; i++) {
        length = subvector_data[i][1]-subvector_data[i][0]+1;
        if (length > max) {
            max = length;
        }
    }
    for (i=0; i<=j; i++) {
        if ((subvector_data[i][1]-subvector_data[i][0]+1) == max) {
            for (f=subvector_data[i][0]; f <= subvector_data[i][1]; f++) {
                printf("%d ", V[f]);
            }
            printf("\n");
        }
    }
}

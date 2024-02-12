#include <stdio.h>
#define maxN 30

/* Algoritmo
 * Nel main registro con input da terminale il vettore chiedendone anticipatamente la lunghezza
 * Poi attivo un ciclo while che chiede di quante posizioni si voglia far ruotare il vettore
 * Nel caso la risposta sia diversa da zero viene chiamata la funzione ruota
 * La funzione ruota() chiama uno switch che a seconda del valore 1 o -1 chiesto come input da terminale all'utente
 * applica una serie di cicli for affinché gli elementi del vettore risultino ruotati
 * appoggiandosi ad un nuovo vettore chiamato appunto newVect[]
 */

void ruota(int v[maxN], int N, int P, int dir);

int main() {
    int N, i=0, j, P=1, dir=0;
    int V[maxN];
    printf("Quanto vuoi che sia lungo il vettore?\n");
    if (scanf("%d", &N) == 1) {
        printf("Scrivi i dati del tuo vettore\n");
        for  (i=0;i<N;i++) {
            scanf("%d", &V[i]);
        }
    }
    else {
        printf("Errore nell'inserimento della lunghezza del vettore");
    }
    for (j=0; j<i; j++) {
        printf("%d ", V[j]);
    }
    printf("\n");
    while (P != 0) {
        printf("Di quante posizioni vuoi far scalare gli elementi del vettore?");
        scanf("%d", &P);
        if (P==0) {
            break;
        }
        printf("In che direzione vuoi ruotare il vettore? [-1 per destra, 1 per sinistra]");
        scanf("%d", &dir);
        ruota(V, N, P, dir);
    }
    return 0;
}
void ruota(int v[maxN], int N, int P, int dir) {
    int i, j;
    if (P > N) {
        printf("P dev'essere minore di N\n");
    } else {
        int newVect[maxN];
        switch (dir) {
            case -1:
                for (i=0; i<P; i++) {
                    newVect[i] = v[N-P+i];
                }
                for (i=0; i<N-P; i++) {
                    newVect[P+i] = v[i];
                }
                for (j=0; j<N; j++) {
                    printf("%d ", newVect[j]);
                }
                break;
            case 1:
                for (i=0; i<N; i++) {
                    newVect[i] = v[P+i];
                }
                for (i=0; i<P; i++) {
                    newVect[N-P+i] = v[i];
                }
                for (j=0; j<N; j++) {
                    printf("%d ", newVect[j]);
                }
                break;
            default:
                printf("Errore\n");
                break;
        }
    }
}
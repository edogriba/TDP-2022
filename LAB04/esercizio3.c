#include <stdio.h>
#define LMAX 20

/* Algoritmo
 * Il main chiede input da terminale all'utente per ottenere il nome del file
 * Una volta ottenuto viene aperto e ne vengono registrati i dati all'interno in alcune variabili ed in una matrice
 * Dopodiché si stampa a terminale la matrice e poi viene attivato un ciclo do-while
 * All'interno del ciclo viene prima ottenuta la dimensione delle sottomatrici che vuole l'utente chiamando la funzione chiediDimensioni
 * Poi viene chiamata la funzione creaSottomatrici che svolge il ruolo centrale di tutto il programma
 * Vengono usate due matrici "d'appoggio" e 4 cicli for annidati per scandire prima le righe della matrice, poi le colonne, poi gli elementi iniziali, gli elementi delle singole sottomatrici
 * Contestualmente viene fatto il confronto per ogni sottomatrice con quella che ha gli elementi che danno la somma massima e in caso sia maggiore viene registrata nella matrice_massima
 * Infine si stampano le sottomatrici e si prosegue con il while finché l'utente non inserisce una dimensione delle sottomatrici non compatibile con la matrice del file
 */

int minimo(int num1, int num2);
int chiediDimensioni(int nr, int nc);
void creaSottomatrici (int dimensione, int nr, int nc,  int matrice[LMAX][LMAX]);

int main () {
    int i, j, nr, nc, dim;
    FILE *fp;
    char nomeFile[LMAX];
    int matrice [LMAX] [LMAX];
    printf("Come si chiama il tuo file?");
    scanf("%s", nomeFile);
    fp = fopen(nomeFile, "r");
    fscanf(fp, "%d %d", &nr, &nc);
    for (i=0; i<nr; i++) {
        for (j = 0; j < nc; j++) {
            fscanf(fp, "%d", &matrice[i][j]);
        }
    }
    for (i=0; i<nr; i++) {
        for (j=0; j<nc; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
    do {
        dim = chiediDimensioni(nr, nc);
        creaSottomatrici(dim, nr, nc, matrice);
    } while (dim != 0);
    fclose(fp);
    return 0;
}

int minimo (int num1, int num2) {
    if (num2 < num1) {
        return num2;
    }
    else {
        return num1;
    }
}

int chiediDimensioni(int nr, int nc) {
    int n;
    printf("Di che dimensione vuoi le sottomatrici?");
    scanf("%d", &n);
    if (n > 0 && n < minimo(nr, nc)) {
        return n;
    }
    else {
        return 0;
    }
}

void creaSottomatrici(int dimensione, int nr, int nc, int matrice[LMAX][LMAX]) {
    if (dimensione == 0) {
        printf("Dimensione delle matrici inserita sbagliata");
    }
    else {
        int i, j, k, l, d=0, e=0, index, kindex;
        int matrice_copia[dimensione] [dimensione];
        int matrice_massima[dimensione][dimensione];
        int max=0, sum=0;
        for (i=0; i<=nr-dimensione; i++) {
            for (j=0; j<=nc-dimensione; j++) {
                for (k=i; k < dimensione+i; k++) {
                    for (l=j; l < dimensione+j; l++) {
                        printf("%d ", matrice[k][l]);
                        sum += matrice[k][l];
                        matrice_copia[d][e] = matrice[k][l];
                        e++;
                    }
                    e = 0;
                    d++;
                    printf("\n");
                }
                if (sum > max ) {
                    max = sum;
                    for (index=0; index<dimensione; index++) {
                        for (kindex=0; kindex< dimensione; kindex++) {
                            matrice_massima[index][kindex] = matrice_copia[index][kindex];
                        }
                    }
                }
                sum = 0, d=0;
                printf("\n");
            }
        }
        printf("La sottomatrice con somma degli elementi massima (%d) è \n\n", max);
        for (i=0; i<dimensione; i++) {
            for (k=0; k< dimensione; k++) {
                printf("%d ", matrice_massima[i][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
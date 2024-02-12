#include <stdio.h>
#define MAXR 50
/* Algoritmo
 * L'algoritmo è molto simile a quello dell'esercizio del laboratorio 2 con le differenze che in questo caso la scelta sull'uso delle funzioni
 * era vincolata dall'esercizio stesso; Le due funzioni che ho creato su suggerimento della traccia servono prima a salvare i dati
 * e poi ad usarli per riconoscere i rettangoli e stamparli ed infine stampare quelli di ampiezza maggiore
 * */


void leggiMatrice(int matrix[MAXR][MAXR], int MAX, int *nr, int * nc); // chiedere se vada bene questo pointer
int riconosciRegione(int matrix[MAXR][MAXR], int nr, int nc, int righe, int colonne, int *base, int *altezza);

int main() {
    int first=1, e;
    int matrix[MAXR][MAXR];
    int nr, nc, r, c, b, h;
    leggiMatrice(matrix, MAXR, &nr, &nc);
    int figure[3][4];
    for (r = 0; r < nr; r++) {
        for (c = 0; c < nc; c++) {
            if (riconosciRegione(matrix, nr, nc, r, c, &b, &h)) {
                printf("Estremo superiore in SX<%d,%d> b=%d, h=%d, Area=%d \n", r, c, b, h, (b) * (h));
                if (first) {
                    figure[0][0] = r;
                    figure[0][1] = c;
                    figure[0][2] = b;
                    figure[0][3] = h;
                    figure[1][0] = r;
                    figure[1][1] = c;
                    figure[1][2] = b;
                    figure[1][3] = h;
                    figure[2][0] = r;
                    figure[2][1] = c;
                    figure[2][2] = b;
                    figure[2][3] = h;
                    first = 0;
                }
                if (figure[0][2] < b) {
                    figure[0][0] = r;
                    figure[0][1] = c;
                    figure[0][2] = b;
                    figure[0][3] = h;
                }
                if (figure[1][3] < h) {
                    figure[1][0] = r;
                    figure[1][1] = c;
                    figure[1][2] = b;
                    figure[1][3] = h;
                }
                if (figure[2][2] * figure[2][3] < (b) * (h)) {
                    figure[2][0] = r;
                    figure[2][1] = c;
                    figure[2][2] = b;
                    figure[2][3] = h;
                }
            };
        }
    }
    printf("\n");
    printf("Max Base; estremo superiore SX<%d,%d> b=%d, h=%d, Area=%d \n", figure[0][0], figure[0][1], figure[0][2], figure[0][3], figure[0][2] * figure[0][3]);
    printf("Max Altezza; estremo superiore SX<%d,%d> b=%d, h=%d, Area=%d \n", figure[1][0], figure[1][1], figure[1][2], figure[1][3], figure[1][2] * figure[1][3]);
    printf("Max Area; estremo superiore SX<%d,%d> b=%d, h=%d, Area=%d \n", figure[2][0], figure[2][1], figure[2][2], figure[2][3], figure[2][2] * figure[2][3]);

    return 0;
}
void leggiMatrice (int matrix[MAXR][MAXR], int MAX, int *nr, int *nc) {
    // variabili utili
    int i, j;
    FILE * fp;
    fp = fopen("mappa.txt", "r" );
    fscanf(fp, "%d %d", nr, nc);
    printf("%d %d\n", *nr, *nc);
    for (i=0; i<*nr; i++) {
        for (j=0; j<*nc; j++) {
            if (j == *nc-1) {
                fscanf(fp, "%d", &matrix[i][j]);
            }
            else {
                fscanf(fp, "%d ", &matrix[i][j]);
            }
        }
    }
    for (i=0; i<*nr; i++) {
        for (j=0; j<*nc; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    fclose(fp);
}

int riconosciRegione(int matrix[MAXR][MAXR], int nr, int nc, int righe, int colonne, int *base, int *altezza) {
    //variabili per cicli
    int k, q, flag =0;
    *base = 0;
    *altezza =0;
            if (righe==0 && colonne == 0) {
                if (matrix[righe][colonne] == 1) {
                    flag =1;
                    for (k=colonne; k < nc; k++) {
                        if (matrix[righe][k] == 1) {
                            continue;
                        }
                        else {
                            break;
                        };
                    }
                    *base = k-colonne;
                    for (q=righe; q < nr; q++) {
                        if (matrix[q][colonne] == 1) {
                            continue;
                        } else {
                            break;
                        };
                    }
                    *altezza = q-righe;
                }
            }
            else if (righe==0) { // in questo caso non ho messo la condizione colonne !=0 perché risultava ridondante
                if (matrix[righe][colonne - 1] == 0 && matrix[righe][colonne] == 1) {
                    flag =1;
                    for (k=colonne; k < nc; k++) {
                        if (matrix[righe][k] == 1) {
                            continue;
                        }
                        else {
                            break;
                        };
                    }
                    *base = k-colonne;
                    for (q=righe; q < nr; q++) {
                        if (matrix[q][colonne] == 1) {
                            continue;
                        } else {
                            break;
                        };
                    }
                    *altezza = q-righe;
                }
            }
            else if (colonne == 0) {
                if (matrix[righe-1][colonne] == 0 && matrix[righe][colonne] == 1) {
                    flag =1;
                    for (k=colonne; k < nc; k++) {
                        if (matrix[righe][k] == 1) {
                            continue;
                        }
                        else {
                            break;
                        };
                    }
                    *base = k-colonne;
                    for (q=righe; q < nr; q++) {
                        if (matrix[q][colonne] == 1) {
                            continue;
                        } else {
                            break;
                        };
                    }
                    *altezza = q-righe;
                }
            }
            else {
                if ( matrix[righe-1][colonne] == 0 && matrix[righe][colonne-1] == 0 && matrix[righe][colonne] ==1) {
                    flag =1;
                    for (k=colonne; k < nc; k++) {
                        if (matrix[righe][k] == 1) {
                            continue;
                        }
                        else {
                            break;
                        };
                    }
                    *base = k-colonne;
                    for (q=righe; q < nr; q++) {
                        if (matrix[q][colonne] == 1) {
                            continue;
                        } else {
                            break;
                        };
                    }
                    *altezza = q-righe;
                }
            }
            return flag;
}

#include <stdio.h>
#define MAX_VALUE 50
/* Algoritmo
 * Ho deciso di dividere il programma in due funzioni: una per leggere i dati in entrata e l'altra per manipolare i dati come richiesto dall'esercizio
 * Per immagazzinare i dati ho scelto di usare una matrice mentre per registrare tutte le informazioni sui rettangoli ho usato un vettore di struct
 * Sono consapevole che probabilmente a livello di memoria non sia forse la scelta più vincente ma ho fatto questa scelta per mettermi alla prova
 * usando una struttura dati un po' più articolata del solito. La logica di base del programma consiste nel fare una ricerca per ogni elemento della matrice
 * sulla casella più in alto e su quella più in basso o solo su una delle due (a seconda dell'indice di riga e di colonna)
 * Se entrambe sono vuote e la matrice è piena allora si tratta di un nuovo rettangolo quindi si fanno partire due cicli for uno per la ricerca della base e l'altro per la ricerca dell'altezza
 * Altrimenti si passa all'elemento successivo.
 * L'ultima parte del codice crea un piccolo vettore per la registrazione delle caratteristiche dei rettangoli con le massime caratteristiche richieste (base, area e altezza)
 * Infine con un ciclo for si passa sopra al vettore dove si sono appena registrati i rettangoli richiesti e li si stampa
 * */

void readDataFile(int matrix[MAX_VALUE][MAX_VALUE], int *nr, int * nc);
void countRect(int matrix[MAX_VALUE][MAX_VALUE], int *nr, int * nc);

int main() {
    int matrix[MAX_VALUE][MAX_VALUE];
    int  nr, nc;
    readDataFile(matrix, &nr, &nc);
    countRect(matrix, &nr, &nc);
    return 0;
}
void readDataFile (int matrix[MAX_VALUE][MAX_VALUE], int *nr, int * nc) {
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

void countRect(int matrix[MAX_VALUE][MAX_VALUE], int *nr, int *nc) {
    //variabili per cicli
    int i, j, k, q, counter=0, index=0, element;
    //variabili flag
    int first = 1;
    // structures
    struct rettangolo {
        int base;
        int altezza;
        int estremi_superiori[2];
    };
    // vettori
    int choices[3][5];
    struct rettangolo figure[15];

    for (i=0; i<*nr; i++) {
        for (j=0; j<*nc; j++) {
            if (i==0 && j == 0) {
                if (matrix[i][j] == 1) {
                    struct rettangolo rettangolino;
                    rettangolino.estremi_superiori[0] = i;
                    rettangolino.estremi_superiori[1] = j;
                    for (k=j; k<*nc; k++) {
                        if (matrix[i][k] == 1) {
                            continue;
                        }
                        else {
                            break;
                        };
                    }
                    rettangolino.base = k-j;
                    for (q=i; q<*nr; q++) {
                        if (matrix[q][j] == 1) {
                            continue;
                        }
                        else {
                            break;
                        };
                    }
                    rettangolino.altezza = q-i;
                    figure[counter] = rettangolino;
                    counter++;
                }
            }
            else if (i==0) { // in questo caso non ho messo la condizione j !=0 perché risultava ridondante
                if (matrix[i][j - 1] == 0 && matrix[i][j] == 1) {
                    struct rettangolo rettangolino;
                    rettangolino.estremi_superiori[0] = i;
                    rettangolino.estremi_superiori[1] = j;
                    for (k = j; k < *nc; k++) {
                        if (matrix[i][k] == 1) {
                            continue;
                        } else {
                            break;
                        };
                    }
                    rettangolino.base = k-j;
                    for (q = i; q < *nr; q++) {
                        if (matrix[q][j] == 1) {
                            continue;
                        } else {
                            break;
                        };
                    }
                    rettangolino.altezza = q-i;
                    figure[counter] = rettangolino;
                    counter++;
                }
            }
            else if (j == 0) {
                if (matrix[i-1][j] == 0 && matrix[i][j] == 1) {
                    struct rettangolo rettangolino;
                    rettangolino.estremi_superiori[0] = i;
                    rettangolino.estremi_superiori[1] = j;
                    for (k = j; k < *nc; k++) {
                        if (matrix[i][k] == 1) {
                            continue;
                        } else {
                            break;
                        };
                    }
                    rettangolino.base = k-j;
                    for (q = i; q < *nr; q++) {
                        if (matrix[q][j] == 1) {
                            continue;
                        } else {
                            break;
                        };
                    }
                    rettangolino.altezza = q-i;
                    figure[counter] = rettangolino;
                    counter++;
                }
            }
            else {
                if ( matrix[i-1][j] == 0 && matrix[i][j-1] == 0 && matrix[i][j] ==1) {
                    struct rettangolo rettangolino;
                    rettangolino.estremi_superiori[0] = i;
                    rettangolino.estremi_superiori[1] = j;
                    for (k = j; k < *nc; k++) {
                        if (matrix[i][k] == 1) {
                            continue;
                        } else {
                            break;
                        };
                    }
                    rettangolino.base = k-j;
                    for (q = i; q < *nr; q++) {
                        if (matrix[q][j] == 1) {
                            continue;
                        } else {
                            break;
                        };
                    }
                    rettangolino.altezza = q-i;
                    figure[counter] = rettangolino;
                    counter++;
                };
            }
        }
    }
    for (i=0; i<counter; i++) {
        if (first) {
            for (index = 0; index < 3; index++) {
                choices[index][0] = figure[i].estremi_superiori[0];
                choices[index][1] = figure[i].estremi_superiori[1];
                choices[index][2] = figure[i].base;
                choices[index][3] = figure[i].altezza;
                choices[index][4] = figure[i].base * figure[i].altezza;
            }
            first = 0;
        } else {
            if (figure[i].base > choices[0][2]) {
                choices[0][0] = figure[i].estremi_superiori[0];
                choices[0][1] = figure[i].estremi_superiori[1];
                choices[0][2] = figure[i].base;
                choices[0][3] = figure[i].altezza;
                choices[0][4] = figure[i].base * figure[i].altezza;
            }
            if (figure[i].base * figure[i].altezza > choices[1][4]) {
                choices[1][0] = figure[i].estremi_superiori[0];
                choices[1][1] = figure[i].estremi_superiori[1];
                choices[1][2] = figure[i].base;
                choices[1][3] = figure[i].altezza;
                choices[1][4] = figure[i].base * figure[i].altezza;
            }
            if (figure[i].altezza > choices[2][3]) {
                choices[2][0] = figure[i].estremi_superiori[0];
                choices[2][1] = figure[i].estremi_superiori[1];
                choices[2][2] = figure[i].base;
                choices[2][3] = figure[i].altezza;
                choices[2][4] = figure[i].base * figure[i].altezza;
            }
        }
    }
    for (element=0; element < index; element++) {
        switch (element) {
            case 0:
                printf("Max Base; estr. sup. SX<%d,%d> b=%d, h=%d, Area=%d \n", choices[element][0], choices[element][1],
                       choices[element][2], choices[element][3], choices[element][4]);
                break;
            case 1:
                printf("Max Area; estr. sup. SX<%d,%d> b=%d, h=%d, Area=%d \n", choices[element][0], choices[element][1],
                       choices[element][2], choices[element][3], choices[element][4]);
                break;
            case 2:
                printf("Max Altezza; estr. sup. SX<%d,%d> b=%d, h=%d, Area=%d \n", choices[element][0],
                       choices[element][1], choices[element][2], choices[element][3], choices[element][4]);
                break;
            default:
                printf("C'è stato un errore");
        }
    }
}

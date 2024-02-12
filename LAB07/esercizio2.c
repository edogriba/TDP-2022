#include <stdio.h>
#define MAX 100
/* Algoritmi di ordinamento
 * Ho implementato tre diverse funzioni di ordinamento con gli algoritmi di ordinamento Selection sort, Insertion sort e Shell sort come richiesto dalla traccia
 * Ho creato un ulteriore funzione chiamata chooseAlgo per scegliere l'algoritmo usando un ciclo for che passa sopra a un comando di switch
 * al fine di far eseguire tutte le funzioni di ordinamento. Ho stampato ogni volta il vettore in input e quello in output riordinato ogni volta.
 * Ho anche stampato come richiesto i vari passi di ogni funzione di ordinamento e anche i passi dei cili interni per ogni ciclo esterno
 * */

void chooseAlgo(int text[][MAX], int row, int length);
void SelectionSort(int testo[], int length);
void InsertionSort(int testo[], int length);
void ShellSort(int testo[], int length);
void printVector(int vector[], int length);

int main() {
    //lettura file
    int nr, i, j, k, elemento, lunghezza_vettore;
    FILE *fp;
    fp = fopen("sort1.txt", "r");
    fscanf(fp, "%d", &nr);
    int matrice[nr][MAX];
    int lunghezze_vettori[nr];
    for (i=0; i<nr; i++) {
        fscanf(fp, "%d ", &lunghezza_vettore);
        for (j=0; j<lunghezza_vettore; j++) {
            if (fscanf(fp, "%d", &elemento) ==1 ) {
                matrice[i][j] = elemento;
            }
        }
        lunghezze_vettori[i] = lunghezza_vettore;
    }
    fclose(fp);
    //fine lettura file
    for (k=0; k < nr; k++) {
        chooseAlgo(matrice, k, lunghezze_vettori[k]);
    }

    return 0;
}

void SelectionSort(int testo[], int length) {
    printf("Dati in input: ");
    printVector(testo, length);
    int numero_scambi=0, counter_ciclo_interno=0, counter_ciclo_esterno=0, counter_iterazioni_totali=0;
    int *p;
    p = testo;
    int i, j, l=0, r=length-1, min;
    int temp;
    for (i = l; i < r; i++) {
        counter_ciclo_interno=0;
        counter_ciclo_esterno++;
        printf("Iterazione del ciclo esterno numero: %d\n", counter_ciclo_esterno);
        min = i;
        for (j = i+1; j <= r; j++) {
            counter_ciclo_interno++;
            if (p[j] < p[min]) {
                min = j;
            }
        }
        printf("Numero iterazioni ciclo interno: %d\n", counter_ciclo_interno);
        counter_iterazioni_totali += counter_ciclo_interno;
        if (min != i) {
            temp = p[i];
            p[i] = p[min];
            p[min] = temp;
            numero_scambi++;
        }

    }
    printf("Dati riordinati: ");
    printVector(testo, length);
    printf("Numero scambi: %d\n", numero_scambi);
    printf("Numero iterazioni : %d\n", counter_iterazioni_totali);
    printf("---------------------------------------------\n");
}
void InsertionSort(int testo[], int length) {
    int numero_scambi=0, counter_ciclo_interno=0, counter_ciclo_esterno=0, counter_iterazioni_totali=0;
    printf("Dati in input: ");
    printVector(testo, length);
    int i, x, j;
    int * p;
    p = testo;
    int l=0, r=length-1;
    for (i = l+1; i <= r; i++) {
        counter_ciclo_interno=0;
        counter_ciclo_esterno++;
        printf("Iterazione del ciclo esterno numero: %d\n", counter_ciclo_esterno);

        x = p[i];
        j = i - 1;
        while (j >= l && x < p[j]){
            p[j+1] = p[j];
            j--;
            numero_scambi++;
            counter_ciclo_interno++;
        }
        printf("Numero iterazioni del ciclo interno: %d\n", counter_ciclo_interno);
        counter_iterazioni_totali += counter_ciclo_interno;
        p[j+1] = x;

    }
    printf("Dati riordinati con Insertion Sort: ");
    printVector(testo, length);
    printf("Numero scambi: %d\n", numero_scambi);
    printf("Numero iterazioni totali : %d\n", counter_iterazioni_totali);
    printf("---------------------------------------------\n");
}
void ShellSort(int testo[], int length) {
    int numero_scambi=0, counter_ciclo_interno=0, counter_ciclo_esterno=0, counter_iterazioni_totali=0;
    printf("Dati in input: ");
    printVector(testo, length);
    int *p;
    p = testo;
    int i, j, x, l=0, r=length-1, h=1;
    while (h < length/3) {
        h = 3 * h + 1;
    }
    while( h >= 1) {
        counter_ciclo_interno=0;
        counter_ciclo_esterno++;
        printf("Iterazione del ciclo esterno numero: %d\n", counter_ciclo_esterno);
        for (i = l + h; i <= r; i++) {
            j = i;
            x = p[i];
            while(j >= l+h && x < p[j-h] ) {
                p[j] = p[j-h];
                j -= h;
                numero_scambi++;
                counter_ciclo_interno++;
            }
            p[j] = x;
            numero_scambi++;
            counter_ciclo_interno++;
        }
        printf("Numero iterazioni del ciclo interno: %d\n", counter_ciclo_interno);
        counter_iterazioni_totali += counter_ciclo_interno;
        h = h/3;
    }
    printf("Dati riordinati con Shell Sort: ");
    printVector(testo, length);
    printf("Numero scambi: %d\n", numero_scambi);
    printf("Numero totale di iterazioni : %d\n", counter_iterazioni_totali);
    printf("---------------------------------------------\n");
}
void chooseAlgo(int text[][MAX], int row, int length) {
    int counter=0, i;
    int text1[length];
    for (i=0; i<length; i++) {
        text1[i] = text[row][i];
    }
    int text2[length];
    for (i=0; i<length; i++) {
        text2[i] = text[row][i];
    }
    int text3[length];
    for (i=0; i<length; i++) {
        text3[i] = text[row][i];
    }
    enum algo {Selection_sort, Insertion_sort, Shell_sort};
    while (counter < 3) {
        switch (counter) {
            case Selection_sort:
                printf("Selection Sort \n");
                SelectionSort(text1, length);
                break;
            case Insertion_sort:
                printf("Insertion Sort \n");
                InsertionSort(text2, length);
                break;
            case Shell_sort:
                printf("Shell Sort \n");
                ShellSort(text3, length);
                break;
            default:
                break;
        }
        counter++;
    }
}
void printVector(int vector[], int length) {
    int w;
    for (w=0; w<length; w++) {
        printf("%d ", vector[w]);
    }
    printf("\n");
}

#include <stdio.h>
#define file "../numeri.txt"
int sum( int num1, int num2, int num3);
int divide(int num1, int num2, int num3);
int product( int num1, int num2, int num3);
int subtraction(int num1, int num2, int num3);

int main() {
    int number, first=1, second=0, temp, primo=0, secondo=0, scartati=0, max, min;
    FILE *fin;
    fin = fopen(file, "r");
    while (fscanf(fin, "%d", &number) == 1){
            //printf("%d ", number);
            if (first) {
                temp=number;
                primo = temp;
                first = 0;
                second = 1;
                max = number;
                min = number;
            }
            else if (second) {
                temp=number;
                secondo = temp;
                second = 0;
                if (number > max) {
                    max = number;
                }
                else if (number < min) {
                    min = number;
                }
            }
            else {
                if (sum(primo, secondo, number) || subtraction(primo, secondo, number) || product(primo, secondo, number) || divide(primo, secondo, number))  {
                    if (number > max) {
                        max = number;
                    }
                    else if (number < min) {
                        min = number;
                    }
                    primo = secondo;
                    temp = number;
                    secondo = temp;
                }
                else {
                    scartati++;
                }
            }
    }
    printf("Numero massimo: %d\n", max);
    printf("Numero minimo: %d\n", min);
    if (scartati != 0) {
        printf("Numeri scartati: ");
        printf("%d", scartati);
    }
    else {
        printf("Non sono stati scartati numeri");
    }
    fclose(fin);
    return 0;
}
int sum(num1, num2, num3) {
    if (num1 + num2 == num3 ) {
        return 1;
    }
    else return 0;
}
int product(num1, num2, num3) {
    if (num1 * num2 == num3) {
        return 1;
    }
    else return 0;
}
int divide(num1, num2, num3) {
    if (num2 != 0) {
        if (num1 / num2 == num3) {
            return 1;
        }
        else return 0; }
    else {
        return 0;
    }
}
int subtraction(num1, num2, num3) {
    if (num1 - num2 == num3) {
        return 1;
    }
    else return 0;
}

/* Algoritmo
 * con un while e fgets prendo in input numero
 * registro i numeri in v1 e v2
 * faccio i confronti usando 4 funzioni
 *
 *
 * */
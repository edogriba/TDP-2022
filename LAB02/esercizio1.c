/*Algoritmo
 * L'algoritmo è stato implementato come indicato
 * Il programma è abbastanza autoesplicativo
 * Le uniche considerazioni che valga la pena di fare riguardano il controllo iniziale per assicurarsi che la scanf prenda in input due numeri
 * e il secondo controllo sul fatto che entrambi i numeri acquisiti siano diversi da zero
 * poiché non si può calcolare il MCD tra due numeri se almeno uno dei due è uno zero
 */
#include <stdio.h>

int main() {

    int num1, num2, temp, result;

    printf("Inserire due numeri di cui si vuole calcolare il MCD ( Massimo Comune Divisore) ");
    if (scanf("%d %d", &num1, &num2) < 2) {
        printf("Comando errato!");
    }
    else if (num1 == 0 || num2 == 0) {
        printf("Non si può fare il MCD tra due numeri di cui uno vale zero");
        }
    else {
        if (num1 > num2 || num1 == num2) {
            result = 1;
            while (result != 0) {
                result = num1 % num2;
                temp = num2;
                num1 = temp;
                temp = result;
                num2 = temp;
            }
            printf("%d", num1);
        } else if (num1 < num2) {
            result = 1;
            while (result != 0) {
                result = num2 % num1;
                temp = num1;
                num2 = temp;
                temp = result;
                num1 = temp;
            }
            printf("%d", num2);
        }
    }
        return 0;
}

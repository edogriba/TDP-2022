#include <stdio.h>
#define PI 3.14
int main(void) {

    char c1, c2;
    float f1;
    float A;


    printf("Quale area vuoi calcolare con cosa vuoi calcolare l'area? ");
    scanf(" %c %c %f%*c", &c1, &c2, &f1);

    if (c1 == 'Q' || c1 == 'q') {
        if (c2 == 'D' || c2 == 'd') {
            A = f1 * f1 / 2;
            printf("Area quadrato: %.3f", A);
        } else if (c2 == 'L' || c2 == 'l') {
            A = f1 * f1;
            printf("Area quadrato: %.3f", A);
        } else {
            printf("Comando errato!");
        }
    }
    else if (c1 == 'C' || c1 == 'c') {
        if (c2 == 'r' || c2 == 'R') {
            A = PI * f1 * f1;
            printf("Area cerchio: %.3f", A);
        }
        else if (c2 == 'd' || c2 == 'D') {
            A = PI * f1 * f1 / 4;
            printf("Area cerchio %.3f", A);
        }
        else {
            printf("Comando errato!");
        }
    }
    else {
        printf("male");
    }
}
// Solamente per questo esercizio non commento il codice poiché è molto basilare ed autoesplicativo
#include <stdio.h>
int main(void) {
    char operator;
    float op1, op2, result;

    printf("Che operazione si vuole eseguire? [ Digita uno tra i seguenti caratteri '+', '-', '*', '/' ] ");
    scanf("%c%*c", &operator);
    if (operator != '+' && operator != '-' && operator != '*' && operator != '/') {
        printf("Comando sbagliato!");
    }
    else {
        printf("Quali son i due operandi? [Scrivere i due operandi separati da uno spazio]");
        scanf("%f %f%*c", &op1, &op2);
        switch (operator) {
            case '+':
                result = op1 + op2;
                printf("%c %.2f", operator, result);
                break;
            case '-':
                result = op1 - op2;
                printf("%c %.2f", operator, result);
                break;
            case '/':
                if (op2 != 0) {
                    result = op1 / op2;
                    printf("%c %.2f", operator, result);
                    break;
                }
                else {
                    printf("Non si può dividere un numero per zero");
                    break;
                }
            case '*':
                result = op1 * op2;
                printf("%c %.2f", operator, result);
                break;
            default:
                printf("Operazione non valida!");
        }
    }
    return 0;
}
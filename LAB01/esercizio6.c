//Algoritmo
/* Si crea una funzione con il costrutto switch per andare per distinguere le quattro operazioni aritmetiche di base
 * Dopodiché si analizza il file riga per riga andnado ad estrarre i due operatori d il segno che andremo attraverso lo switch ad assegnare ad un'operazione
 * Piccolo appunto: in questo caso l'ho fatto con due costrutti diversi ovvero fscanf e sscanf solo per allenamento senza un motivo preciso
 * Una flag indica se il file sia stato aperto per la prima volta e quindi sia necessario aprirlo in modalità write oppure non si tratti della prima apertura e lo si debba aprire in modalità append
 */


#include <stdio.h>

void operazioni (float operando1, float operando2, char operazione, int w_a);

int main(void) {
    FILE *input;
    char s[80];
    char operator;
    float op1, op2;
    int first=1;


    input = fopen("../Operations.txt", "r");
    fscanf(input, "%c %f %f ", &operator, &op1, &op2);

    if (operator != '+' && operator != '-' && operator != '*' && operator != '/') {
        printf("Comando sbagliato!");
    } else {
        operazioni(op1, op2, operator, first);
        first = 0;
    }
    while (fgets(s, 80, input) != NULL) {
        sscanf(s, "%c %f %f ", &operator, &op1, &op2);
        if (operator != '+' && operator != '-' && operator != '*' && operator != '/') {
            printf("Comando sbagliato!");
        }
        else {
            operazioni(op1, op2, operator, first);
        }
    }
    fclose(input);
    return 0;
}
void operazioni (float operando1, float operando2, char operazione, int w_a) {
    FILE *output;
    float result;
    if (w_a) {
        output = fopen("../Results.txt", "w");
    }
    else {
        output = fopen("../Results.txt", "a");
    }
    switch (operazione) {
        case '+':
            result = operando1 + operando2;
            fprintf(output, "%c %.2f\n", operazione, result);
            break;
        case '-':
            result = operando1 - operando2;
            fprintf(output, "%c %.2f\n", operazione, result);
            break;
        case '/':
            if (operando2 != 0) {
            result = operando1 / operando2;
                fprintf(output, "%c %.2f\n", operazione, result);
                break;
            }
            else {
                fprintf(output, "Non si può dividere un numero per zero");
                break;
            }
        case '*':
            result = operando1 * operando2;
            fprintf(output, "%c %.2f\n", operazione, result);
            break;
        default:
            printf("Operazione non valida!");
    }
    fclose(output);
}
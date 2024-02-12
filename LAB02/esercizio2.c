# include <stdio.h>

int main(void) {
    int num, num1 , num2, temp, counter, result;
    num1 = 0;
    num2 = 1;
    printf("Dammi il numero al quale mi devo fermare per la serie di Fibonacci: ");
    scanf(" %d%*c", &num);
    if (num < 0 || num ==0) {
        printf("Riprova con un numero positivo");
    }
    else if (num == 1) {
        printf("%d", num);
    }
    else {
        printf(" %d %d ", num1, num2);
        result = num1 + num2;
        temp = num2;
        num1 = temp;
        num2 = result;
        counter = 2;
        while (counter < num) {
            printf("%d ", num2);
            result = num1 + num2;
            temp = num2;
            num1 = temp;
            num2 = result;
            counter++;
            }

        }
    return 0;
}
#include <stdio.h>
int main () {
    int i;
    char nomeFile[20];
    printf("Come si chiama il tuo file?");
    scanf("%s", nomeFile);
    fopen(nomeFile, "r");


    return 0;
}

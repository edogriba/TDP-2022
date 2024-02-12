#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    char c, temp, prev, carattere='a';
    int counter, i, true=1, first=1, second=0, dollar=0, numero=0;
    FILE *fin, *fout;
    fin = fopen("../sorgente1.txt", "r");
    fout = fopen("../outputdecomp.txt", "w");
    while (true) {
        c = (char) fgetc(fin);
        if (c != EOF) {
            if (first) {
                temp = c;
                prev = temp;
                first = 0;
                fprintf(fout, "%c", c);
            }
            else if (c!='$' && !dollar) {
                temp = c;
                prev = temp;
                fprintf(fout, "%c", c);

            }
            else if(c =='$') {
                carattere = (char)prev;
                dollar = 1;
            }
            else {
                numero = c -'0';
                for (i=0; i<numero; i++) {
                    fprintf(fout, "%c", carattere);
                }
                dollar = 0;
            }

        }
        else {
            true = 0;
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
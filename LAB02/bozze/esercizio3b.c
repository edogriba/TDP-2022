#include <stdio.h>
#include <string.h>

int main() {
    FILE *fin, *fout;
    fout = fopen("../outputcomp.txt", "w");
    fin = fopen("../sorgente.txt", "r");
    int true=1, first=1, counter=0, x2=0, xmolte=0, oltre9=0;
    char c, prev='$', temp;

    while (true) {
        c = (char)fgetc(fin);
        if ((c != EOF && c!= prev) || (first)) {
            if (first) {
                first = 0;
            }
            if (x2 && !xmolte) {

                fprintf(fout, "%c", prev);
                x2 =0;
            }
            else if (x2 && xmolte) {
                fprintf(fout, "$%d", counter);
                x2 =0;
                xmolte =0;
            }
            counter=0;
            fprintf(fout, "%c", c);
            temp= c;
            prev = temp;
            if (oltre9) {
                oltre9=0;
            }
        }
        else if (c != EOF && c == prev && oltre9) {
            if (x2 && !xmolte) {

                fprintf(fout, "%c", prev);
                x2 =0;
            }
            else if (x2 && xmolte) {
                fprintf(fout, "$%d", counter);
                x2 =0;
                xmolte =0;
            }
            counter=0;
            fprintf(fout, "%c", c);
            temp= c;
            prev = temp;
            oltre9 =0;
        }
        else if (c != EOF &&  c == prev) {
            counter++;
            if (!x2) {
                x2 =1;
            }
            else if (!xmolte ) {
                xmolte = 1;
            }
            if ( counter>8 ) {
                fprintf(fout, "%c$%d", prev, counter);
                counter = 0;
                x2 =0;
                xmolte =0;
                oltre9 =1;
            }
        }
        else {

            true = 0 ;
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;

}
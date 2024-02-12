//Algoritmo
/* Ho organizzato il codice in una macrofunzione chiamata reformat file
 * Con la funzione di reformattazione prendo in input carattere per carattere
 * Per ogni caratter faccio aumentare il conto dei caratteri in modo che quando arrivino a 26 faccio stampare un '\n' per andare a capo
 * Dopo la verifica della lunghezza della riga arriva la parte della sistemazione dei caratteri
 * Se il carattere è un numero viene sostituito da un asterisco
 * Se il carattere appartiene all'insieme dei segni d'interpunzione e il successivo è uno spazio o non lo è,
 * si attivano una cascata di flag che servono per dirigere il flusso e far eseguire al programma la formattazioen desiderata
 */
#include <stdio.h>
#include <ctype.h>
void reformat_file(FILE *fin, FILE *fout);
int main() {
    FILE *finput, *foutput_formattato;
    finput = fopen("../input.txt", "r");
    foutput_formattato = fopen("../output.txt", "w");
    reformat_file(finput, foutput_formattato);
    fclose(finput);
    fclose(foutput_formattato);
    return 0;
}
void reformat_file (FILE *fin, FILE *fout) {
    int flag = 1, spazi, i, counter = 0, punt = 0, isblank = 0, registro = 0, flagged=0;
    char c;
    while (flag) {
        c = (char) fgetc(fin);
        if (c != EOF) {
            if (c != '\n') {
                counter++;
                if (counter > 25) {
                    registro = counter;
                    fprintf(fout, "| %c:%d", 'c', registro-1);
                    fprintf(fout, "%c", '\n');
                    counter = 0;
                }
            } else {
                if (counter < 25) {
                    registro = counter;
                    spazi = 25 - counter -1;
                    if (flagged) {
                        spazi--;
                        flagged =0;
                    }
                    for (i = 0; i < spazi; i++) {
                        fprintf(fout, "%c", ' ');
                    }
                    fprintf(fout, "| %c:%d", 'c', registro+1);
                    counter = 0;
                }
            }
            if (isdigit(c)) {
                fprintf(fout, "%c", '*');
            } else if (c == ',' || c == '.' || c == '!' || c == '?' || c == ';' || c == ':' ) {
                punt = 1;
                fprintf(fout, "%c", c);
                if (c == '.' || c == '!' || c == '?') {
                    punt = 2;
                }
            } else if (isblank) {
                if (isalpha(c) && c != ' ' && c != '\n') {
                    fprintf(fout, "%c", toupper(c));
                    isblank = 0;
                    punt = 0;
                }
            } else if (punt) {
                if (isalpha(c) && punt == 2) {
                    fprintf(fout, "%c%c", ' ', toupper(c));
                    punt = 0;
                    flagged = 1;
                } else if (c != ' ' && c != '\n') {
                    fprintf(fout, "%c%c", c, ' ');
                    punt = 0;
                    flagged = 1;
                } else if (punt == 2) {
                    if (c == '\n') {
                        counter = 0;
                    }
                    fprintf(fout, "%c", c);
                    isblank = 1;
                } else {
                    fprintf(fout, "%c", c);
                    punt = 0;
                }
            } else {
                if (c == '\n') {
                    counter = 0;
                }
                fprintf(fout, "%c", c);
                punt = 0;
            }
        } else {
            if (counter > 25) {
                registro = counter;
                fprintf(fout, "| %c:%d", 'c', registro-1);
                fprintf(fout, "%c", '\n');
                counter = 0;
            }
            else {
            if (counter < 25) {
                registro = counter;
                spazi = 25 - counter -1;
                if (flagged) {
                    spazi--;
                    flagged =0;
                }
                for (i = 0; i < spazi; i++) {
                    fprintf(fout, "%c", ' ');
                }
                fprintf(fout, "| %c:%d", 'c', registro+1);
                counter = 0;
            }
        }
            flag = 0;
        }
    }
}
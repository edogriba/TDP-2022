#include <stdio.h>
#include <string.h>
#define MAX_PAROLE 30
#define LUNGHEZZA_MAX_PAROLE 20 // ho assunto che la lunghezza massima sia di una parola che della sua sostituzione fosse di 30 caratteri
#define MAX_STRINGA 200
// Algoritmo
/*
 * Prendo in input il file dizionario con la funzione registraDati()--> faccio fscanf sulla prima riga e prendo in input il numero delle ricodifiche
 *  Dopo registro in una struct dove ci sono due campi: il campo parola e il campo traduzione
 *  Infine la funzione ritorna un intero indicante il numero delle ricodifiche che uso come input della funzione successiva leggiSostituisci
 *  In quest'altra funzione controllo prima di tutto che ci sia il '\n' alla fine altrimenti lo aggiungo
 *  Dopodiché attivo una serie di cicli annidati che fanno in modo di prendere per ogni parola del dizionario la sua lunghezza e creare un vettore copia
 *  del vettore riga della stessa lunghezza della parola del dizionario. Questo vettore si aggiorna dopo ogni confronto con la parola in modo da confrontare tutta la riga con la parola
 *  Nel caso in cui siano uguali il vettore copia e la parola allora si attiva una parte del codice che fa in modo di sostituire la parte uguale con la traduzione secondo
 *  quanto registrato nella struct globale. La riga modificata quindi servirà come input per i nuovi cicli di confronti.
 *  Prima di prendere in input la riga successiva stampo la riga modificata sul file di output
 */

// struct globale
struct associazione {
    char traduzione[LUNGHEZZA_MAX_PAROLE];
    char parola[LUNGHEZZA_MAX_PAROLE];
};
// vettore di struct globale
struct associazione elenco[MAX_PAROLE];

//signature delle funzioni
void leggiSostituisci( int numero_righe);
int registraDati (void);

int main() {
    int righe;
    righe = registraDati();
    leggiSostituisci(righe);
    return 0;
}
int registraDati(void) {
    //dichiarazioni variabili utili per i cicli
    int i, j, righe;
    // dichiarazioni vettori
    char stringa[MAX_STRINGA];
    char numero[MAX_STRINGA];
    // puntatore al file
    FILE *dizionario;
    dizionario = fopen("dizionario.txt", "r");

    fscanf(dizionario, "%d\n", &righe);
    for (i=0; i < righe; i++) {
        fscanf(dizionario, "%s ", numero);
        fgets(stringa, MAX_STRINGA, dizionario);
        if (stringa[strlen(stringa)-1] == '\n') {
            stringa[strlen(stringa)-1] = '\0';
        }
        struct associazione a;
        strcpy(a.traduzione, numero);
        for (j=0; j<MAX_STRINGA; j++) {
            a.parola[j] = stringa[j];
        }
        elenco[i] = a;
    }
    fclose(dizionario);
    return righe;
}
void leggiSostituisci (int numero_righe ) {
    // variabili usate per scandire i cicli
    int k, f, assoc, index, e, c;
    // variabili che registrano valori su cui eseguo delle operazioni
    int lunghezza_parola, lunghezza_riga, fino_alla_fine, nuova_lunghezza, numero_iterazioni=0;
    // puntatori ai file
    FILE * sorgente, *output;
    sorgente = fopen("sorgente.txt", "r");
    output = fopen("output.txt", "w");
    // dichiarazione vettori
    char riga[MAX_STRINGA];
    char parte_iniziale[MAX_STRINGA];
    char parte_finale[MAX_STRINGA];

    while (fgets(riga, MAX_STRINGA, sorgente) != NULL) {
        lunghezza_riga = strlen((riga));
        if (riga[lunghezza_riga-1] != '\n') {
            riga[lunghezza_riga] = '\n';
            riga[lunghezza_riga+1] = '\0';
            lunghezza_riga++;
        }
        for (assoc=0; assoc < numero_righe; assoc++) {
            lunghezza_parola = strlen(elenco[assoc].parola);
            char vect[lunghezza_parola];
            for (k=0; k < lunghezza_riga - lunghezza_parola; k++) {
                index = 0;
                for (f=k; f < lunghezza_parola+k; f++) {
                    vect[index] = riga[f];
                    index++;
                }
                if (strcmp(vect, elenco[assoc].parola) == 0) {
                    for (c=0; c<k; c++) {
                        parte_iniziale[c] = riga[c];
                    }
                    parte_iniziale[c] = '\0';
                    fino_alla_fine=0;
                    for (c=k+lunghezza_parola; c<=lunghezza_riga; c++) {
                        parte_finale[fino_alla_fine]=riga[c];
                        fino_alla_fine++;
                    }
                    parte_finale[fino_alla_fine+1]= '\0';
                    strcat(parte_iniziale, elenco[assoc].traduzione);
                    strcat(parte_iniziale, parte_finale);
                    nuova_lunghezza = strlen(parte_iniziale);
                    for (e=0; e < nuova_lunghezza; e++) {
                        riga[e] = parte_iniziale[e];
                    }
                    riga[e]= '\0';
                    lunghezza_riga = strlen((riga));
                    k=f-1;
                }
            }
        }
        fprintf(output, "%s", riga); //stampa la riga alla fine di ogni iterazione sulla riga
        numero_iterazioni++;
    }
    fclose(sorgente);
    fclose(output);
}
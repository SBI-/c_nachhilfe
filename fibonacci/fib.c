#include <stdio.h>
#include <stdlib.h>

const int START = 2;
const int MAX_LIMIT = 46;

int main()
{
    int limit;
    // Anfangswerte setzen
    int f1 = 0, f2 = 1, result, n;

    // Limit von user einlesen
    printf("Limit: ");
    scanf("%d", &limit);
    
    // Anfangswerte ausgaben
    printf("n = %d \tfn = %10d \t", 0, f1);
    printf("n = %d \tfn = %10d \t", 1, f2);

    // Fibonacci zwischen unterem Limit und Usereingabe ausgeben.
    // Vergleich mit MAX_LIMIT um Wraparound der Fibonaccizahlen zu verhindern.
    for (n = START; n <= limit && n <= MAX_LIMIT; ++n) {
        // Resultat berechnen
        result = f1 + f2;

        // Fibonacci glieder setzen
        f1 = f2;
        f2 = result;

        // Zeilenumbruch für 2-spaltiges layout
        if (n % 2 == 0) {
            printf("\n");
        }

        // Resultat ausgeben
        printf("n = %d \tfn = %10d \t", n, result);
    }

    // Texteingabefeld aufräumen
    printf("\n");
    return EXIT_SUCCESS;
}

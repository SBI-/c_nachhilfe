#include <stdio.h>
#include <stdlib.h>

int main()
{
    int basis;
    int exponent;

    // resultat auf 1 setzen (x^0 ist immer 1)
    int resultat = 1;

    // basis einlesen
    printf("basis: ");
    scanf("%d", &basis);

    // exponent einlesen
    printf("exponent: ");
    scanf("%d", &exponent);

    // nur berechnen falls exponent grösser 0
    if (exponent > 0) {
        // resultat gleich basis
        resultat = basis;

        // solange exponent grösser 1
        while (exponent > 1) {
            // resultat gleich resultat * basis
            resultat *= basis;

            // exponent dekrementieren
            --exponent;
        }
    }

    // resultat ausgeben
    printf("%d\n", resultat);

    return EXIT_SUCCESS;
}

#include <stdio.h>

int main()
{
    int zahl;
    int ziffer;
    int resultat = 0;
    // zahl einlesen
    printf("zahl: ");
    scanf("%d", &zahl);
    // solange zahl > 0
    while (zahl > 0) {
        // ziffer = zahl modulo 10
        ziffer = zahl % 10;
        // resultat = resultat + ziffer
        resultat += ziffer;
        // zahl = zahl / 10
        zahl /= 10;
    }
    // resultat ausgeben
    printf("resultat: %d\n", resultat);
    return 0;
}

#include <stdio.h>

int main()
{
    int zahl;
    int resultat;
    // zahl einlesen
    printf("zu spiegelnde Zahl: ");
    scanf("%d", &zahl);
    // solange zahl grösser 0
    while (zahl > 0) {
        // resultat = resultat * 10
        resultat *= 10;
        // resultat = resultat + ziffer
        resultat += zahl % 10;
        // zahl = zahl / 10
        zahl /= 10;
    }
    // resultat ausgeben
    printf("%d\n", resultat);

    return 0;
}

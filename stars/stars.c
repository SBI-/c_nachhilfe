/* Bibliotheken */
#include <stdlib.h>
#include <stdio.h>

/* Konstanten */
#define TRUE 1
#define FALSE 0

/* Funktionsdeklaration */
int sum(int x, int y);

/* Hauptprogramm */
int main() 
{
    int anzahl;
    scanf("%d", &anzahl);
    while (anzahl >= 0) {
        printf("*");
        --anzahl;
    }

    printf("\n");
    return EXIT_SUCCESS;
}

int sum(int x, int y)
{
    return x + y;
}

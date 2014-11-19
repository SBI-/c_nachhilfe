#include <stdlib.h>
#include <stdio.h>

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

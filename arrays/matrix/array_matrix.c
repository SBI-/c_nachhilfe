#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void fill_table(Matrix *table);
int digit_count(int number);
void print_table(Matrix *table);
int read_input();

int main()
{
    int width = read_input();

    Matrix *table = create_matrix(width, width);
    fill_table(table);
    print_table(table);
    free_matrix(table);

    return EXIT_SUCCESS;
}

void print_table(Matrix *table)
{
    int limit = table->width - 1;
    int padding = digit_count(table->values[limit][limit]) + 1;
    print_matrix(table, padding);
}


void fill_table(Matrix *table)
{
    for (int row = 0; row < table->height; ++row) {
        for (int col = 0; col < table->width; ++col) {
            table->values[row][col] = (row + 1)  * (col + 1);
        }
    }
}

int digit_count(int number)
{
    return (int)log10(number) + 1;
}

int read_input()
{
    int input;
    printf("Enter limit: ");
    int scan = scanf("%d", &input);
    if (scan != 1) {
        fprintf(stderr, "Invalid input.\n");
        exit(EIO);
    }

    return input;
}

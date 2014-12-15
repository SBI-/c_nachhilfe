#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fill_table(int width, int table[][width]);
void print_table(int width, int table[][width]);
int digit_count(int number);
int read_input();

int main()
{
    int width = read_input();
    int table[width][width];

    fill_table(width, table);
    print_table(width, table);

    return EXIT_SUCCESS;
}


void fill_table(int width, int table[][width])
{
    for (int row = 0; row < width; ++row) {
        for (int col = 0; col < width; ++col) {
            table[row][col] = (row + 1) * (col + 1);
        }
    }
}

void print_table(int width, int table[][width])
{
    int padding = digit_count(table[width - 1][width - 1]) + 1;

    for (int row = 0; row < width; ++row) {
        for (int col = 0; col < width; ++col) {
            printf("%*d", padding, table[row][col]);
        }
        printf("\n");
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

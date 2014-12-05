#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char SEPARATOR = '-';

void print_times_table(const int size);
int digit_count(const int number);
char *build_separator_string(const int length, const char character);

int main(int argc, char* argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Wrong number of arguments.\n");
        exit(EIO);
    }

    int size = atoi(argv[1]);
    print_times_table(size);
    return EXIT_SUCCESS;
}

/**
 * Prints a times table (like in elementary school) for the given size.
 *
 * @param size maximum width and height of the table.
 */
void print_times_table(const int size)
{
    int padding_width = digit_count(size * size) + 1;
    char *separator_string = build_separator_string(size * padding_width, SEPARATOR);

    // print table header numbers
    printf("%*s", padding_width, "");
    for (int row = 1; row <= size; ++row) {
        printf("%*d", padding_width, row);
    }

    // print separator line
    printf("\n%*s%s", padding_width, "", separator_string);

    // print times table
    for (int row = 1; row <= size; ++row) {
        // print table column labels
        printf("\n%-*d|", padding_width - 1, row);

        for (int column = 1; column <= size; ++column) {
            printf("%*d", padding_width, column * row);
        }
    }

    printf("\n");
    free(separator_string);
}

/**
 * Calculates how many digits a given number is composed of.
 *
 * @param number number for which to count digits.
 * @return number of digits.
 */
int digit_count(const int number)
{
    return (int)log10(number) + 1;
}

/**
 * Creates a string of length characters, consisting only of a given character.
 *
 * @attention must be free'd by the user.
 * @param length desired length of the string.
 * @param character character with which string is filled.
 * @return Null-terminated string of length, filled with character.
 */
char *build_separator_string(const int length, const char character)
{
    char *string = malloc(length + 1);
    memset(string, character, length);
    string[length] = '\0';
    return string;
}

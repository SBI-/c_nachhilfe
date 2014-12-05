#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

const char *EIO_MESSAGE = "Invalid input, exiting program";
const char *PADDING = "";

void generate_pyramid(int height_max);
int read_user_input(const char *query);

int main()
{
    int height = read_user_input("Enter height");
    generate_pyramid(height);
    return EXIT_SUCCESS;
}

int read_user_input(const char *query)
{
    int input;

    printf("%s: ", query);

    if (scanf("%d", &input) != 1) {
        fprintf(stderr, "%s\n", EIO_MESSAGE);
        exit(EIO);
    }

    return input;
}

void generate_pyramid(const int height_max)
{
    for (int height = 1; height <= height_max; ++height) {
        printf("%*s", height_max - height, PADDING);

        for (int stars = 0; stars < height; ++stars) {
            printf("* ");
        }

        printf("\n");
    }
}

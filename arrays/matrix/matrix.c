#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

Matrix *create_matrix(int height, int width)
{
    Matrix *matrix = malloc(sizeof(Matrix));

    matrix->height = height;
    matrix->width = width;

    matrix->values = malloc(sizeof(int*) * height);

    for (int row = 0; row < height; ++row) {
        matrix->values[row] = malloc(sizeof(int) * width);
    }

    return matrix;
}

void free_matrix(Matrix *matrix)
{
    for (int row = 0; row < matrix->height; ++row) {
        free(matrix->values[row]);
    }

    free(matrix->values);
    free(matrix);
}

void print_matrix(Matrix *matrix, int padding)
{
    for (int row = 0; row < matrix->height; ++row) {
        for (int col = 0; col < matrix->width; ++col) {
            printf("%*d", padding, matrix->values[row][col]);
        }
        printf("\n");
    }
}

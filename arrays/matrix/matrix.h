#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

typedef struct {
    int **values;
    int height;
    int width;
} Matrix;

Matrix *create_matrix(int height, int width);
void free_matrix(Matrix *matrix);
void print_matrix (Matrix *matrix, int padding);

#endif

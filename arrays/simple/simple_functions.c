#include <stdio.h>
#include <stdlib.h>

int string_length(char string[]);
int string_length_short(char *string);
int sum_array(int array[], int size);
int max_value(int array[], int size);
void sort_array(int array[], int size);

int main()
{
    int length;
    char string[] = "Lorem ipsum bli blabb und so weiter";
    length = string_length(string);
    printf("%d\n", length);

    char string2[] ="Let's see if this works!";
    length = string_length_short(string2);
    printf("%d\n", length);

    int numbers[] = {4, 16, 256, 2, 64, 128, 2, 32, 512, 8};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("%d\n", sum_array(numbers, size));
    printf("%d\n", max_value(numbers, size));

    sort_array(numbers, size);

    for (int i = 0; i < size; ++i) {
        printf("%d ", numbers[i]);
    }

    printf("\n");

    return EXIT_SUCCESS;
}


int sum_array(int array[], int size)
{
    int sum = 0;

    for (int pos = 0; pos < size; ++pos) {
        sum += array[pos];
    }

    return sum;
}

int max_value(int array[], int size)
{
    int max = array[0];

    for (int pos = 0; pos < size; ++pos) {
        if (array[pos] > max) {
            max = array[pos];
        }
    }

    return max;
}

void sort_array(int array[], int size)
{
    int temp;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (array[j] > array[i]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int string_length(char string[])
{
    int position = 0;
    int count = 0;

    while (string[position] != '\0') {
        ++count;
        ++position;
    }

    return count;
}

int string_length_short(char *string)
{
    int count = 0;

    while (*string++) {
        ++count;
    }

    return count;
}

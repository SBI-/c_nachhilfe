#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isLetter(const char c);
bool isLower(const char c);
bool isUpper(const char c);
char toUpper(const char c);

int main()
{
    char *sentence = "This is an example!";
    int length = strlen(sentence) + 1;

    char *upper_sentence = malloc(length * sizeof(char));
    strncpy(upper_sentence, sentence, length);

    printf("%s\n", sentence);

    for (int i = 0; i < length - 1; ++i) {
        char current = sentence[i];
        if (!isLetter(current)) {
            continue;
        }

        if (isLower(current)) {
            upper_sentence[i] = toUpper(current);
        }

    }

    printf("%s\n", upper_sentence);

    return EXIT_SUCCESS;
}

bool isLetter(const char c)
{
    return isUpper(c) || isLower(c);
}

bool isUpper(const char c)
{
    return (c >= 'A' && c <= 'Z');
}

bool isLower(const char c)
{
    return c >= 'a' && c <= 'z';
}

char toUpper(const char c)
{
    return c - 32;
}

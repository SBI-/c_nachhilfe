#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_letter(const char c);
bool is_lower(const char c);
bool is_upper(const char c);
char to_upper(const char c);

int main()
{
    char *sentence = "This is an example!";
    int length = strlen(sentence) + 1;

    char *upper_sentence = malloc(length * sizeof(char));
    strncpy(upper_sentence, sentence, length);

    printf("%s\n", sentence);

    for (int i = 0; i < length - 1; ++i) {
        char current = sentence[i];
        if (!is_letter(current)) {
            continue;
        }

        if (is_lower(current)) {
            upper_sentence[i] = to_upper(current);
        }
    }

    printf("%s\n", upper_sentence);
    return EXIT_SUCCESS;
}

bool is_letter(const char c)
{
    return is_upper(c) || is_lower(c);
}

bool is_upper(const char c)
{
    return (c >= 'A' && c <= 'Z');
}

bool is_lower(const char c)
{
    return c >= 'a' && c <= 'z';
}

char to_upper(const char c)
{
    return c - 32;
}

#include <stdio.h>
#include <stdbool.h>

static bool is_blank(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

char *shrink_space(char *dest, const char *src, size_t n)
{
    size_t i, j;

    if (n == 0)
        return dest;

    for (i = 0, j = 0; i < n && src[i] != '\0'; i++) {
        if (is_blank(src[i])) {
            if (i == 0 || !is_blank(src[i - 1])) {
                if (j + 1 < n) {
                    dest[j++] = ' ';
                }
            }
        } else {
            if (j + 1 < n) {
                dest[j++] = src[i];
            }
        }
    }

    dest[j] = '\0';
    return dest;
}
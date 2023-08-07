#include <stddef.h>

char *my_strstr(const char *haystack, const char *needle) {
    if (*needle == '\0') {
        return (char *)haystack; // Empty needle matches at the beginning of the haystack
    }

    while (*haystack != '\0') {
        const char *h = haystack;
        const char *n = needle;

        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }

        if (*n == '\0') {
            return (char *)haystack; // Substring found
        }

        haystack++;
    }

    return NULL; // Substring not found
}


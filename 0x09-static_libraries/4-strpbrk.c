#include <stddef.h>

char *_strpbrk(const char *str, const char *accept)
{
    unsigned char *ptr;
    unsigned char *accept_bytes;

    ptr = (unsigned char *)str;
    accept_bytes = (unsigned char *)accept;

    while (*ptr != '\0')
    {
        for (const char *c = accept_bytes; *c != '\0'; c++)
        {
            if (*ptr == *c)
                return (char *)ptr;
        }

        ptr++;
    }

    return NULL;
}


#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    struct dog my_dog = {
        "Poppy",     // Name
        3.5,         // Age
        "Bob"        // Owner
    };

    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog.name, my_dog.age);
    return (0);
}


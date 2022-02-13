/*
** EPITECH PROJECT, 2020
** malloc
** File description:
** malloc
*/

#include "malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void *ptr = malloc(nmemb * size);

    if (ptr)
        memset(ptr, 0, nmemb * size);
    return ptr;
}

void *realloc(void *ptr, size_t size)
{
    void *new_ptr;

    if (ptr && (size_t)(NEXT(ptr - M) - ptr) >= size)
        return (ptr);
    new_ptr = malloc(size);
    if (!new_ptr)
        return (ptr);
    if (ptr)
        memmove(new_ptr, ptr, size);
    free(ptr);
    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    return (realloc(ptr, size * nmemb));
}
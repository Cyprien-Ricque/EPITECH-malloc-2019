/*
** EPITECH PROJECT, 2020
** malloc
** File description:
** malloc
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <glob.h>

#define META_DATA (int)sizeof(m_t)
#define M META_DATA
#define TRUE 12
#define FALSE 24
#define DESTROYED -84
#define NEXT(ptr) ((m_t *)(ptr))->next
#define PREV(ptr) ((m_t *)(ptr))->prev
#define SBRK_S(page_nb) (page_nb * (getpagesize() * 2)) + 32 * getpagesize()

void m(char const *str);
void print_memory(char const *distc, const void *addr, size_t size);

typedef  struct __attribute__((__packed__, aligned(16))) m {
    void *next;
    void *prev;
} m_t;

extern void *sbrk_0;

#endif
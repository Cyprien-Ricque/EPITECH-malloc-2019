/*
** EPITECH PROJECT, 2020
** malloc
** File description:
** malloc
*/

#include "malloc.h"

void merge_next(m_t *ptr)
{
    if (NEXT(NEXT(ptr)) && NEXT(NEXT(ptr)) + M < sbrk_0 &&
        ((m_t *)((m_t *)(ptr->next))->next)->prev) {
        ptr->next = ((m_t *)(ptr->next))->next;
        ((m_t *)(ptr->next))->prev = ptr - M;
    }
}

void merge_prev(m_t *ptr)
{
    if (PREV(ptr))
        PREV(NEXT(ptr)) = PREV(ptr);
}

void free(void *ptr)
{
    if (ptr && ptr < sbrk_0 &&
        NEXT(ptr - M) && NEXT(ptr - M) + M < sbrk_0 && !PREV(NEXT(ptr - M))) {
        if (!NEXT(NEXT((ptr - M)))) {
            memset(ptr - M, 0, M);
            return;
        }
        ((m_t *)((m_t *)(ptr - M))->next)->prev = ptr - M;
    }
}
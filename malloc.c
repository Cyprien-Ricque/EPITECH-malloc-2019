/*
** EPITECH PROJECT, 2020
** malloc
** File description:
** malloc
*/

#include "malloc.h"

void *sbrk_0 = NULL;

void *find_emplacement(void *head, size_t size)
{
    void *bucket = head;
    void *best_bucket = NULL;
    int optimal = -1;

    while (bucket && bucket + M < sbrk_0) {
        if (((m_t *)bucket)->next && ((m_t *)bucket)->next + M < sbrk_0 &&
            ((m_t *)((m_t *)bucket)->next)->prev &&
            (size_t)(((m_t *)bucket)->next - bucket) >= size + M &&
            (((m_t *)bucket)->next - bucket < optimal || optimal == -1)) {
            best_bucket = bucket;
            optimal = (int)(((m_t *)bucket)->next - bucket);
        }
        bucket = ((m_t *)bucket)->next;
    }
    return (best_bucket);
}

void *new_emplacement(size_t size, void *current)
{
    void *bucket = NULL;
    size_t pad;
    size_t page_nb = 1;
    size_t to_sbrk;

    if (!current) {
        current = sbrk(0);
        sbrk_0 = current;
    }
    for (to_sbrk = 16; to_sbrk < (size_t)(size + META_DATA); to_sbrk *= 2);
    if (to_sbrk > ((size_t)sbrk_0 - (size_t)current)) {
        pad = (to_sbrk) - ((size_t)sbrk_0 - (size_t)current);
        for (; pad >= (size_t)(getpagesize() * 2); pad -= getpagesize() * 2,
            ++page_nb);
        sbrk_0 = sbrk(SBRK_S(page_nb)) + SBRK_S(page_nb);
    }
    bucket = current;
    NEXT(bucket) = bucket + to_sbrk;
    PREV(bucket) = NULL;
    return (bucket);
}

void *malloc(size_t size)
{
    static void *head = NULL;
    static void *current = NULL;
    void *bucket = NULL;

    bucket = find_emplacement(head, size);
    if (!bucket) {
        bucket = new_emplacement(size, current);
        current = ((m_t *)bucket)->next;
    } else {
        ((m_t *)((m_t *)bucket)->next)->prev = NULL;
    }
    if (!head)
        head = bucket;
    return (bucket + META_DATA);
}
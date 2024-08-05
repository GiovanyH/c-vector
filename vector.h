#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    int len;
    int cap;
} array_header;

#define new_vector(TYPE, NAME) \
    TYPE *NAME = (void*)(((array_header*)malloc(sizeof(array_header) + sizeof(TYPE)*8)) + 1); \
    array_header *HEADER##NAME = vec_get_hdr(NAME); \
    HEADER##NAME->cap = 8; \
    HEADER##NAME->len = 0;

#define vec_get_hdr(SB)      ((array_header *)(SB) - 1)

#define vec_push(SB, ELEM)   (vec_expand((void**)&(SB), sizeof (*(SB))), (SB)[vec_get_hdr(SB)->len++] = (ELEM))
#define vec_pop(SB)          (vec_shrink((void**)&(SB), sizeof(*(SB))))

static inline void vec_expand(void **sb, size_t isz) {
    array_header *h = vec_get_hdr(*sb);
    if (h->len >= h->cap) {
        h->cap *= 2;
        *sb = (void*)(((array_header*)realloc(h, sizeof(array_header) + h->cap*isz)) + 1);
    }
}

static inline void vec_shrink(void **sb, size_t isz) {
    array_header *h = vec_get_hdr(*sb);
    if (--h->len < h->cap - 8) {
        h->cap -= 8;
        *sb = (void*)(((array_header*)realloc(h, sizeof(array_header) + h->cap*isz)) + 1);
    }
}

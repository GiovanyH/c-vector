#ifndef F_VECTOR
#define F_VECTOR

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

typedef struct {
        int len;
        int cap;
} array_header;

#define new_vector(TYPE, NAME) \
    TYPE *NAME; \
    array_header *HEADER; \
    assert(&NAME != NULL); \
    HEADER = malloc(sizeof(array_header) + sizeof(TYPE)*8); \
    HEADER->cap = 8; \
    HEADER->len = 0; \
    NAME = HEADER+1;

#define vec_get_hdr(SB)      ((array_header *)SB-1)

#define vec_get_len(SB)      (SB ? vec_get_hdr(SB)->len : 0)
#define vec_get_capacity(SB) (SB ? vec_get_hdr(SB)->cap : 0)

#define vec_push(SB, ELEM)   (vec_append_e(&(SB), sizeof (*(SB))), (SB)[vec_get_len((SB))-1] = (ELEM))
#define vec_pop(SB)          (vec_pop_e(&(SB), sizeof(*(SB))))

#define vec_free(SB)         (SB ? free(vec_get_hdr(SB)), 0 : 0)


void vec_append_e(void **sb, size_t isz) {
    array_header *h = vec_get_hdr(*sb);
    if (h->len+1 > h->cap) {
        h->cap *= 2;
        h = realloc(h, sizeof(array_header) + h->cap*isz);
        *sb = h+1;
    }
    h->len++;
}

void vec_pop_e(void **sb, size_t isz) {
	array_header *h;

	h = vec_get_hdr(*sb);
	if (h->len-1 < h->cap-8) {
		h->cap-=8;
		h = realloc(h, sizeof(array_header) + h->cap*isz);
		*sb = h+1;
	}
	h->len--;
}

#endif

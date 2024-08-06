# C-Vector
Code:
```
#define new_vector(TYPE, NAME) \
    TYPE *NAME = (TYPE*)((int*)malloc(2 * sizeof(int) + sizeof(TYPE) * 8) + 2); \
    ((int *)NAME)[-2] = 0; ((int *)NAME)[-1] = 8;

#define vec_get_hdr(SB) ((int*)(SB) - 2)
#define vec_push(SB, ELEM) vec_expand((void**)&(SB), sizeof(ELEM), vec_get_hdr(SB)), (SB)[vec_get_hdr(SB)[0]++] = (ELEM)
#define vec_pop(SB, TYPE) vec_shrink((void**)&(SB), sizeof(TYPE), vec_get_hdr(SB))

static inline void vec_expand(void **sb, size_t isz, int *h) {
    if (h[0] >= h[1]) *sb = (void*)((int*)realloc(h, 2 * sizeof(int) + (h[1] *= 2) * isz) + 2);
}

static inline void vec_shrink(void **sb, size_t isz, int *h) {
    if (--h[0] < h[1] - 8) *sb = (void*)((int*)realloc(h, 2 * sizeof(int) + (h[1] -= 8) * isz) + 2);
}
```
Have fun!

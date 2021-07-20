#ifndef F_VECTOR
#define F_VECTOR

#include <stdio.h>
#include <stdlib.h>

#define vector(type, name, block_size)\
typedef struct {\
	type* begin;\
	type* cursor;\
	type* end;\
	const size_t block_size_bytes;\
} vector;\
\
const long int vec_get_len_bytes(vector v) {return (v.cursor - v.begin)*sizeof(type);}\
const long int vec_get_len(vector v) {return (v.cursor - v.begin);}\
const long int vec_get_allocated(vector v) {return (v.end - v.begin);}\
const long int vec_get_allocated_bytes(vector v) {return (v.end - v.begin)*sizeof(type);}\
\
void vec_realloc(vector *v, const size_t new_size_bytes) {\
	const size_t length = vec_get_len(*v);\
	v->begin = realloc(v->begin, new_size_bytes);\
	v->cursor = v->begin + length;\
	v->end = v->begin + new_size_bytes/sizeof(type) - 1;}\
\
void vec_init(vector *v) {\
	v->begin = malloc(v->block_size_bytes);\
	v->cursor = v->begin;\
	v->end = v->begin + v->block_size_bytes/sizeof(type) - 1;}\
\
void vec_free(vector *v) {free(v->begin); v->begin = v->end = v->cursor = NULL;}\
\
void vec_set(vector *v, const int index, const type value) {if(v->end - v->begin > 0) v->begin[index] = value;}\
\
void vec_push(vector *v, const type value) {\
	while(v->end < v->cursor+1) {vec_realloc(v, vec_get_len_bytes(*v) + v->block_size_bytes);}\
	++v->cursor; vec_set(v, vec_get_len(*v), value);}\
\
vector name = {NULL, NULL, NULL, block_size};

#endif

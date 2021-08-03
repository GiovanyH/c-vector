#include "vector.h"
#include <time.h>

int main(void){
	srand(time(NULL));

	new_vector(int, v); // declaring the vector
	printf("vector capacity is %d integers\n", vec_get_capacity(v));

	#define NITERS 10
	for (int i = 0; i < NITERS; i++) {
		vec_push(v, rand());
	}
	printf("pushed 10 elements to vector\n");
	
	printf("length: %d, capacity: %d\n", vec_get_len(v), vec_get_capacity(v));

	for (int i = vec_get_len(v); i > 7; i--) vec_pop(v);
	printf("popped 2 elements from vector\n");
	printf("length: %d, capacity: %d\n", vec_get_len(v), vec_get_capacity(v));

	vec_free(v);
}

#include "vector.h"
#include <time.h>

vector(int, vec, 16);


void vec_print() {
    const size_t v_length = vec_get_len(vec);
    for (int i = 0; i <= v_length; i++) {
        printf("v[%d] = %d\n", i, vec.begin[i]);
    }
}

int main(void) {
	srand(time(NULL));
	vec_init(&vec);
	vec_set(&vec, 0, rand());
	for(int i = 0; i < 100; i++) {
		printf("i = %d\n", i);
		vec_push(&vec, rand());
	}
	vec_print();
	vec_free(&vec);
	
	return 0;
}

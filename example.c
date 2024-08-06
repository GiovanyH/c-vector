#include "vector.h"

int main() {
    new_vector(int, vec);
    for (int i = 0; i < 20; ++i) {
        vec_push(vec, i);
        printf("Pushed: %d, Length: %d, Capacity: %d\n", i, vec_get_hdr(vec)[0], vec_get_hdr(vec)[1]);
    }
    for (int i = 0; i < 10; ++i) {
        vec_pop(vec, int);
        printf("Popped, Length: %d, Capacity: %d\n", vec_get_hdr(vec)[0], vec_get_hdr(vec)[1]);
    }
    free(vec_get_hdr(vec));
    return 0;
}

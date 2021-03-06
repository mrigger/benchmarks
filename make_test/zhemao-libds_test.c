#include <string.h>

#include "chayai.h"

#include "zhemao-libds/vector.h"

BENCHMARK(zhemao, libds, 100, 1) {
    vector_p vec = create_vector();
    vector_p subvec;
    int x;
    char *str = "hello, world";
    char *str2 = "goodbye, world";

    for (x = 0; x < 1024*1024; x++) {
        vector_add(vec, (void *) str, strlen(str) + 1);
    }

    vector_remove(vec, 4);

    subvec = subvector(vec, 1, 1000);

    destroy_vector(subvec);
    destroy_vector(vec);
}

int main(int argc, char** argv) {

    REGISTER_BENCHMARK(zhemao, libds); // Simple, memory-safe data-structures in C

    RUN_BENCHMARKS(argc, argv);

    return 0;
}
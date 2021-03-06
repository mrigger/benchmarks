#include <string.h>
#include <stdlib.h>

#include "chayai.h"

#include "josephg-librope/rope.h"

#define LOREM_IPSUM "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet."
#define LOREM_IPSUM10 LOREM_IPSUM LOREM_IPSUM LOREM_IPSUM LOREM_IPSUM LOREM_IPSUM LOREM_IPSUM LOREM_IPSUM LOREM_IPSUM LOREM_IPSUM LOREM_IPSUM
#define LOREM_IPSUM100 LOREM_IPSUM10 LOREM_IPSUM10 LOREM_IPSUM10 LOREM_IPSUM10 LOREM_IPSUM10 LOREM_IPSUM10 LOREM_IPSUM10 LOREM_IPSUM10 LOREM_IPSUM10 LOREM_IPSUM10
#define LOREM_IPSUM1000 LOREM_IPSUM100 LOREM_IPSUM100 LOREM_IPSUM100 LOREM_IPSUM100 LOREM_IPSUM100 LOREM_IPSUM100 LOREM_IPSUM100 LOREM_IPSUM100 LOREM_IPSUM100 LOREM_IPSUM100

volatile uint8_t *str;

BENCHMARK(josephg, librope, 100, 10) {
    rope *r = rope_new();

    rope_insert(r, 0, (uint8_t*)LOREM_IPSUM1000);

    for(int i = 0; i < 50; i++) {
        rope_insert(r, 100+139*i+(997*i)%569, (uint8_t*)LOREM_IPSUM); // interleaved insertion of substrings
        rope_del(r, 100+139*i+(997*i)%569+20, (i*139)%137+1);
    }

    str = rope_create_cstr(r);
    str[4] = 'A';
    free((void*)str);

    rope_free(r);
}

int main(int argc, char** argv) {

    REGISTER_BENCHMARK(josephg, librope); // rope library for C

    RUN_BENCHMARKS(argc, argv);

    return 0;
}
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "chayai.h"

#include "bashrc-libdeep/src/globals.h"
#include "bashrc-libdeep/src/deeplearn.h"
#include "bashrc-libdeep/src/deeplearndata.h"

#define TITLE     "Concrete Slump Training"
#define DATA_FILE "bashrc-libdeep/examples/concreteslump/slump_test.data"

BENCHMARK(libdeep, learn, 10, 1) {
    int no_of_outputs = 4;
    int output_field_index[] = { 7,8,9,10 };
    float error_threshold_percent[] = { 10.5f, 10.5f, 10.5f, 40.0f };
    unsigned int random_seed = 123;

    deeplearn learner;
    deeplearndata_read_csv(DATA_FILE,
                           &learner,
                           4*4, 3,
                           no_of_outputs,
                           output_field_index, 0,
                           error_threshold_percent,
                           &random_seed);

    deeplearn_set_learning_rate(&learner, 0.9f);

    deeplearn_set_pruning(&learner, 10000, 0.9f);

    deeplearn_set_dropouts(&learner, 1.1f);

    learner.history.interval = 500000;

    deeplearn_set_title(&learner, TITLE);

    while (deeplearndata_training(&learner) != 0);

    deeplearn_free(&learner);
}

int main(int argc, char** argv) {

    REGISTER_BENCHMARK(libdeep, learn); // A deep learning library for C/C++

    RUN_BENCHMARKS(argc, argv);

    return 0;
}
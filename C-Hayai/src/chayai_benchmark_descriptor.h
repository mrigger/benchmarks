#ifndef CHAYAI_BENCHMARKER_DATA_H
#define CHAYAI_BENCHMARKER_DATA_H

#include <stdint.h>

typedef struct CHayaiBenchmarkDescriptor
{
    struct CHayaiBenchmarkSingleRunResult (*runFunction)(void);
    const char* fixtureName;
    const char* benchmarkName;
    unsigned int runs;
    unsigned int iterations;
    unsigned int warmup;

    struct CHayaiBenchmarkDescriptor* next;
} CHayaiBenchmarkDescriptor;



#endif // CHAYAI_BENCHMARKER_DATA_H

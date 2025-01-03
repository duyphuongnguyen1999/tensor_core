#ifndef TENSOR_H
#define TENSOR_H

#include "dtype.h"

typedef struct Tensor
{
    void *data;
    size_t ndims;
    size_t *shape;
    size_t *stride;
    dtype dtype;
    float *grad;
    bool require_grad;

    (float *)at(int position[]);
} Tensor;

#endif
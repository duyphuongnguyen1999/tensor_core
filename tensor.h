#ifndef TENSOR_H
#define TENSOR_H

#include "dtype.h"

typedef struct Tensor
{
    void *data;
    size_t ndims;
    size_t *shape;
    size_t *num_ele;
    size_t *strides;
    dtype dtype;
    float *grads;
    bool requires_grad;

    (float *)at(int position[]);
} Tensor;

#endif
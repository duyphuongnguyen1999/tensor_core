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
    Dtype dtype;
    float *grads;
    bool requires_grad;

    (float *)at(int position[]);
} Tensor;

Tensor *empty_tensor(size_t shape[], size_t ndims, Dtype dtype);
Tensor *zeros_tensor(size_t shape[], size_t ndims, Dtype dtype);
Tensor *ones_tensor(size_t shape[], size_t ndims, Dtype dtype);
void free_tensor(Tensor *tensor);

#endif
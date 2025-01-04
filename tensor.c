#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "tensor.h"

Tensor *empty_tensor(size_t shape[], size_t ndims, dtype dtype)
{
    assert(ndims >= 0 && "Number of dimensions must be equal or greater than zero");
    // assert(shape != NULL && "shape array cannot be NULL");

    // Allocate memory for Tensor structure
    Tensor *tensor = (Tensor *)malloc(sizeof(Tensor));
    assert(tensor != NULL && "Memory allocation for Tensor failed");

    tensor->shape = shape;
    tensor->ndims = ndims;

    // Allocate memory for strides
    tensor->strides = (size_t *)malloc(tensor->ndims * sizeof(size_t));
    assert(tensor->strides != NULL && "Memory allocation for strides failed");

    // Initialize strides and calculate total number of elements
    tensor->num_ele = 1;
    for (size_t i = 0; i < ndims; i++)
    {
        tensor->num_ele *= shape[i];
    }
    tensor->stride[ndims - 1] = 1; // Last dimension stride is always 1
    for (size_t i = ndims - 2; i >= 0; i--)
    {
        tensor->stride[i] = tensor->shape[i + 1] * tensor->strides[i + 1];
    }

    // Allocate memory for data (base on dtype.size)
    tensor->data = (float *)malloc(tensor->num_ele * dtype.size);

    // Initialize other tensor attributes
    tensor->grads = NULL;
    tensor->requires_grad = false;

    return tensor;
}

Tensor *zeros(size_t shape[], size_t ndims)
{
}

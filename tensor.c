#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "tensor_core.h"

// Global pointer for "this" instance
static Tensor *this = NULL;

Tensor *initialize_tensor(size_t ndims, size_t shape[])
{
    assert(ndims >= 0);
    // Allocate memory for Tensor structure
    this = (Tensor *)malloc(sizeof(Tensor));

    if (ndims == 0) // Scalar tensors
    {
        this->shape = NULL;
    }

    this->ndims = ndims;
    this->shape = shape;
    size_t n_elements = 1;
    for (size_t i = 0; i < ndims; i++)
    {
        n_elements *= shape[i];
    }
    this->data = (float *)malloc(n_elements * sizeof(float));
    this->grad = NULL;
    this->require_grad = false;

    return this;
}

float at(int position[])
{
}

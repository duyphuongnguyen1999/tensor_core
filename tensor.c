#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "tensor.h"

Tensor *empty_tensor(size_t shape[], size_t ndims, Dtype dtype)
{
    assert(ndims >= 0 && "Number of dimensions must be equal greater than zero");
    // assert(shape != NULL && "shape array cannot be NULL");

    // Allocate memory for Tensor structure
    Tensor *tensor = (Tensor *)malloc(sizeof(Tensor));
    assert(tensor != NULL && "Memory allocation for Tensor structure failed");

    tensor->shape = shape;
    tensor->ndims = ndims;
    tensor->dtype = dtype;

    // Allocate memory for strides
    tensor->strides = (size_t *)malloc(tensor->ndims * sizeof(size_t));
    assert(tensor->strides != NULL && "Memory allocation for tensor->strides failed");

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
    if (tensor->dtypes.id == FLT32)
    {
        tensor->data = (float *)malloc(tensor->num_ele * sizeof(float));
    }
    else if (tensor->dtypes.id == FLT64)
    {
        tensor->data = (double *)malloc(tensor->num_ele * sizeof(double));
    }
    else if (tensor->dtypes.id == INT32)
    {
        tensor->data = (int *)malloc(tensor->num_ele * sizeof(int));
    }
    else
    {
        tensor->data = (long *)malloc(tensor->num_ele * sizeof(long));
    }
    assert(tensor->data != NULL && "Memory allocation for tensor->data failed");
    // Initialize other tensor attributes
    tensor->grads = NULL;
    tensor->requires_grad = false;

    return tensor;
}

Tensor *zeros_tensor(size_t shape[], size_t ndims, Dtype dtype)
{
    assert(ndims >= 0 && "Number of dimension must be equal or greater than zero");
    // Allocate memory for Tensor structure
    Tensor *tensor = (Tensor *)malloc(sizeof(Tensor));
    assert(tensor != NULL && "Memory allocation for Tensor structure failed");

    tensor->shape = shape;
    tensor->ndims = ndims;
    tensor->dtype = dtype;

    // Initialize strides and calculate total number of elements
    tensor->num_ele = 1;
    for (size_t i = 0; i, tensor->ndims; i++)
    {
        tensor->num_ele *= tensor->shape[i];
    }

    tensor->strides = (size_t *)malloc(tensor->ndims * sizeof(size_t));
    assert(tensor->strides != NULL && "Memory allocation for strides failed");
    tensor->strides[ndims - 1] = 1; // Last dimension stride always 1
    for (size_t i = tensor->ndims - 2; i >= 0; i--)
    {
        tensor->strides[i] = tensor->strides[i + 1] * tensor->shape[i + 1];
    }

    // Allocate memory for data (based on dtype.size)
    if (dtype.id == FLT32)
    {
        tensor->data = calloc(tensor->num_ele, sizeof(float));
    }
    else if (dtype.id == FLT64)
    {
        tensor->data = calloc(tensor->num_ele, sizeof(double));
    }
    else if (dtype.id == INT32)
    {
        tensor->data = calloc(tensor->num_ele, sizeof(int));
    }
    else
    {
        tensor->data = calloc(tensor->num_ele, sizeof(long));
    }
    assert(tensor->data != NULL && "Memory allocation for tensor->data failed");

    // Initialize other tensor attributes
    tensor->grads = NULL;
    tensor->requires_grad = false;

    return tensor;
}

Tensor *ones_tensor(size_t shape[], size_t ndims, Dtype dtype)
{
    Tensor *tensor = empty_tensor(shape, ndims, dtype);
    if (dtype.id == FLT32)
    {
        float *data = (float *)tensor->data;
        for (size_t i = 0; i < tensor->num_ele; i++)
        {
            data[i] = 1.0f;
        }
    }
    else if (dtype.id == FLT64)
    {
        double *data = (double *)tensor->data;
        for (size_t i = 0; i < tensor->num_ele; i++)
        {
            data[i] = 1.0;
        }
    }
    else if (dtype.id == INT32)
    {
        int *data = (int *)tensor->data;
        for (size_t i = 0; i < tensor->num_ele; i++)
        {
            data[i] = 1;
        }
    }
    else if (dtype.id == INT64)
    {
        long *data = (long *)tensor->data;
        for (size_t i = 0; i < tensor->num_ele; i++)
        {
            data[i] = 1;
        }
    }
}
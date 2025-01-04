#ifndef TENSOR_CORE_H
#define TENSOR_CORE_H

#include "tensor.h"
#include "dtype.h"

Tensor *empty_tensor(size_t shape[], size_t ndims, Dtype dtype);
Tensor *zeros_tensor(size_t shape[], size_t ndims, Dtype dtype);
Tensor *ones_tensor(size_t shape[], size_t ndims, Dtype dtype);

#endif
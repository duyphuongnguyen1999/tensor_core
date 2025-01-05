#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "tensor_core.h"

Tensor *kaiming_he_init(Tensor tensor, size_t in_features)
{
    double stddev = sqrt(2 / in_features);

    // Populate the tensor with values from N(0, stddev^2)
    if (tensor->dtype.id == FLT32)
    {
        float *data = (float *)tensor->data;
        for (size_t i = 0; i < tensor->num_ele; i++)
        {
            data[i] = (float)normal_distribution(0.0, stddev);
        }
    }
    else if (tensor->dtype.id == FLT64)
    {
        double *data = (double *)tensor->data;
        for (size_t i = 0; i < tensor->num_ele; i++)
        {
            data[i] = normal_distribution(0.0, stddev);
        }
    }
    else
    {
        assert(false && "Kaiming He initialization is only supported for floating-point types");
    }
}
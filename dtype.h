typedef enum dtype_id
{
    INT32, // int
    INT64, // long
    FLT32, // float
    FLT64  // double
} dtype_id;

typedef struct Dtype
{
    const char *name;
    size_t size;
    dtype_id id;
} Dtype;

const Dtype int32 = {"32bits_integer", sizeof(int), INT32};
const Dtype int64 = {"64bits_integer", sizeof(long), INT64};
const Dtype float32 = {"32bits_float", sizeof(float), FLT32};
const Dtype float64 = {"64bits_float", sizeof(double), FLT64};
typedef enum dtype_id
{
    INT32, // int
    INT64, // long
    FLT32, // float
    FLT64  // double
} dtype_id;

typedef struct dtype
{
    const char *name;
    size_t size;
    dtype_id id;
} dtype;

const dtype int32 = {"32bits_integer", sizeof(int), INT32};
const dtype int64 = {"64bits_integer", sizeof(long), INT64};
const dtype float32 = {"32bits_float", sizeof(float), FLT32};
const dtype float64 = {"64bits_float", sizeof(double), FLT64};
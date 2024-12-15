#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Unsigned int types.
typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;
// Signed int types.
typedef signed char      i8;
typedef signed short     i16;
typedef signed int       i32;
typedef signed long long i64;
// Floating point types
typedef float  f32;
typedef double f64;
// Boolean types
typedef int  b32;
typedef char b8;

/*
Memory layout
u64 capacity = number elements that can be held
u64 length = number of elements currently contained
u64 stride = size of each element in bytes
void* elements
*/
enum
{
    DARRAY_CAPACITY,
    DARRAY_LENGTH,
    DARRAY_STRIDE,
    DARRAY_FIELD_LENGTH
};

#define printArray(nums, numsSize)                                                                                     \
    {                                                                                                                  \
        int i = 0;                                                                                                     \
        for (; i < numsSize; i++)                                                                                      \
        {                                                                                                              \
            printf("%i ", nums[i]);                                                                                    \
        }                                                                                                              \
        printf("\n");                                                                                                  \
    }

#define DARRAY_DEFAULT_CAPACITY 1
#define DARRAY_RESIZE_FACTOR 2

#define darray_create(type) _darray_create(DARRAY_DEFAULT_CAPACITY, sizeof(type))
#define darray_reserve(type, capacity) _darray_create(capacity, sizeof(type))
#define darray_destroy(array) _darray_destroy(array);

#define darray_push(array, value)                                                                                      \
    {                                                                                                                  \
        typeof(value) temp = value;                                                                                    \
        array = _darray_push(array, &temp);                                                                            \
    }

// NOTE: could use __auto_type for temp above, but intellisense
// for VSCode flags it as an unknown type. typeof() seems to
// work just fine, though. Both are GNU extensions.
#define darray_pop(array, valuePtr) _darray_pop(array, valuePtr)

#define darray_insert_at(array, index, value)                                                                          \
    {                                                                                                                  \
        typeof(value) temp = value;                                                                                    \
        array = _darray_insert_at(array, index, &temp);                                                                \
    }

#define darray_pop_at(array, index, value_ptr) _darray_pop_at(array, index, value_ptr)
#define darray_clear(array) _darray_field_set(array, DARRAY_LENGTH, 0)
#define darray_capacity(array) _darray_field_get(array, DARRAY_CAPACITY)
#define darray_length(array) _darray_field_get(array, DARRAY_LENGTH)
#define darray_stride(array) _darray_field_get(array, DARRAY_STRIDE)
#define darray_set_length(array, value) _darray_field_set(array, DARRAY_LENGTH, value)

void *_darray_create(u64 length, u64 stride);
void  _darray_destroy(void *array);
u64   _darray_field_get(void *array, u64 field);
void  _darray_field_set(void *array, u64 field, u64 value);
void *_darray_resize(void *array);
void *_darray_push(void *array, const void *valuePtr);
void  _darray_pop(void *array, void *dest);
void *_darray_pop_at(void *array, u64 index, void *dest);
void *_darray_insert_at(void *array, u64 index, void *valuePtr);

/// sort///
void swap(int *a, int *b);
int  partition(int *arr, int low, int high);
void quicksort(int *arr, int low, int high);

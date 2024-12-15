#include "defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *_darray_create(u64 length, u64 stride)
{
    u64  headerSize = DARRAY_FIELD_LENGTH * sizeof(u64);
    u64  arraySize = length * stride;
    u64 *newArray = malloc(headerSize + arraySize);
    memset(newArray, 0, headerSize + arraySize);

    newArray[DARRAY_CAPACITY] = length;
    newArray[DARRAY_LENGTH] = 0;
    newArray[DARRAY_STRIDE] = stride;

    return (void *)(newArray + DARRAY_FIELD_LENGTH);
}
void _darray_destroy(void *array)
{
    u64 *header = (u64 *)array - DARRAY_FIELD_LENGTH;
    u64  headerSize = DARRAY_FIELD_LENGTH * sizeof(u64);
    u64  totalSize = headerSize + header[DARRAY_CAPACITY] * header[DARRAY_STRIDE];

    free(header);
}
u64 _darray_field_get(void *array, u64 field)
{
    u64 *header = (u64 *)array - DARRAY_FIELD_LENGTH;
    return header[field];
}
void _darray_field_set(void *array, u64 field, u64 value)
{
    u64 *header = (u64 *)array - DARRAY_FIELD_LENGTH;
    header[field] = value;
}
void *_darray_resize(void *array)
{
    u64   length = darray_length(array);
    u64   stride = darray_stride(array);
    void *newArray = _darray_create(DARRAY_RESIZE_FACTOR * length, stride);

    memcpy(newArray, array, length * stride);
    _darray_field_set(newArray, DARRAY_LENGTH, length);

    _darray_destroy(array);

    return newArray;
}
void *_darray_push(void *array, const void *valuePtr)
{
    u64 length = darray_length(array);
    u64 stride = darray_stride(array);

    if (length >= darray_capacity(array))
    {
        array = _darray_resize(array);
    }

    u64 addr = (u64)array;
    addr += length * stride;
    memcpy((void *)addr, valuePtr, stride);
    _darray_field_set(array, DARRAY_LENGTH, length + 1);
    return array;
}
void _darray_pop(void *array, void *dest)
{
    u64 length = darray_length(array);
    u64 stride = darray_stride(array);

    u64 addr = (u64)array;
    addr += (length - 1) * stride;
    memcpy((void *)addr, dest, stride);
    _darray_field_set(array, DARRAY_LENGTH, length - 1);
}
void *_darray_pop_at(void *array, u64 index, void *dest)
{
    u64 length = darray_length(array);
    u64 stride = darray_stride(array);

    if (index >= length)
    {
        printf("Index outside the bounds of this array!! Length: %i index: %i", (i32)length, (i32)index);
        return array;
    }

    u64 addr = (u64)array;
    if (index != length - 1)
    {
        memcpy((void *)(addr + (index * stride)), (void *)(addr + ((index + 1) * stride)), stride * (length - index));
    }
    _darray_field_set(array, DARRAY_LENGTH, length - 1);
    return array;
}
void *_darray_insert_at(void *array, u64 index, void *valuePtr)
{
    u64 length = darray_length(array);
    u64 stride = darray_stride(array);

    if (index >= length)
    {
        printf("Index outside the bounds of this array!! Length: %i index: %i", (i32)length, (i32)index);
        return array;
    }
    if (length >= darray_capacity(array))
    {
        array = _darray_resize(array);
    }

    u64 addr = (u64)array;

    if (index != length - 1)
    {
        memcpy((void *)(addr + ((index + 1) * stride)), (void *)(addr + (index * stride)), stride * (length - index));
    }
    memcpy((void *)(addr + (index * stride)), valuePtr, stride);

    _darray_field_set(array, DARRAY_LENGTH, length + 1);

    return array;
}

#define printArray(nums, numsSize)                                                                                     \
    {                                                                                                                  \
        int i = 0;                                                                                                     \
        for (; i < numsSize; i++)                                                                                      \
        {                                                                                                              \
            printf("%i ", nums[i]);                                                                                    \
        }                                                                                                              \
        printf("\n");                                                                                                  \
    }

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *arr, int low, int high)
{

    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int *arr, int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

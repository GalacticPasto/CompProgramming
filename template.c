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

#define darrayCreate(type) _darrayCreate(DARRAY_DEFAULT_CAPACITY, sizeof(type))
#define darrayReserve(type, capacity) _darrayCreate(capacity, sizeof(type))
#define darrayDestroy(array) _darrayDestroy(array);

#define darrayPush(array, value)                                                                                       \
    {                                                                                                                  \
        typeof(value) temp = value;                                                                                    \
        array = _darrayPush(array, &temp);                                                                             \
    }

// NOTE: could use __auto_type for temp above, but intellisense
// for VSCode flags it as an unknown type. typeof() seems to
// work just fine, though. Both are GNU extensions.
#define darrayPop(array, valuePtr) _darrayPop(array, valuePtr)

#define darrayInsertAt(array, index, value)                                                                            \
    {                                                                                                                  \
        typeof(value) temp = value;                                                                                    \
        array = _darrayInsertAt(array, index, &temp);                                                                  \
    }

#define darrayPopAt(array, index, value_ptr) _darrayPopAt(array, index, value_ptr)
#define darrayClear(array) _darrayFieldSet(array, DARRAY_LENGTH, 0)
#define darrayCapacity(array) _darrayFieldGet(array, DARRAY_CAPACITY)
#define darrayLength(array) _darrayFieldGet(array, DARRAY_LENGTH)
#define darrayStride(array) _darrayFieldGet(array, DARRAY_STRIDE)
#define darraySetLength(array, value) _darrayFieldSet(array, DARRAY_LENGTH, value)

void *_darrayCreate(u64 length, u64 stride);
void  _darrayDestroy(void *array);
u64   _darrayFieldGet(void *array, u64 field);
void  _darrayFieldSet(void *array, u64 field, u64 value);
void *_darrayResize(void *array);
void *_darrayPush(void *array, const void *valuePtr);
void  _darrayPop(void *array, void *dest);
void *_darrayPopAt(void *array, u64 index, void *dest);
void *_darrayInsertAt(void *array, u64 index, void *valuePtr);

void *_darrayCreate(u64 length, u64 stride)
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
void _darrayDestroy(void *array)
{
    u64 *header = (u64 *)array - DARRAY_FIELD_LENGTH;
    u64  headerSize = DARRAY_FIELD_LENGTH * sizeof(u64);
    u64  totalSize = headerSize + header[DARRAY_CAPACITY] * header[DARRAY_STRIDE];

    free(header);
}
u64 _darrayFieldGet(void *array, u64 field)
{
    u64 *header = (u64 *)array - DARRAY_FIELD_LENGTH;
    return header[field];
}
void _darrayFieldSet(void *array, u64 field, u64 value)
{
    u64 *header = (u64 *)array - DARRAY_FIELD_LENGTH;
    header[field] = value;
}
void *_darrayResize(void *array)
{
    u64   length = darrayLength(array);
    u64   stride = darrayStride(array);
    void *newArray = _darrayCreate(DARRAY_RESIZE_FACTOR * length, stride);

    memcpy(newArray, array, length * stride);
    _darrayFieldSet(newArray, DARRAY_LENGTH, length);

    _darrayDestroy(array);

    return newArray;
}
void *_darrayPush(void *array, const void *valuePtr)
{
    u64 length = darrayLength(array);
    u64 stride = darrayStride(array);

    if (length >= darrayCapacity(array))
    {
        array = _darrayResize(array);
    }

    u64 addr = (u64)array;
    addr += length * stride;
    memcpy((void *)addr, valuePtr, stride);
    _darrayFieldSet(array, DARRAY_LENGTH, length + 1);
    return array;
}
void _darrayPop(void *array, void *dest)
{
    u64 length = darrayLength(array);
    u64 stride = darrayStride(array);

    u64 addr = (u64)array;
    addr += (length - 1) * stride;
    memcpy((void *)addr, dest, stride);
    _darrayFieldSet(array, DARRAY_LENGTH, length - 1);
}
void *_darrayPopAt(void *array, u64 index, void *dest)
{
    u64 length = darrayLength(array);
    u64 stride = darrayStride(array);

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
    _darrayFieldSet(array, DARRAY_LENGTH, length - 1);
    return array;
}
void *_darrayInsertAt(void *array, u64 index, void *valuePtr)
{
    u64 length = darrayLength(array);
    u64 stride = darrayStride(array);

    if (index >= length)
    {
        printf("Index outside the bounds of this array!! Length: %i index: %i", (i32)length, (i32)index);
        return array;
    }
    if (length >= darrayCapacity(array))
    {
        array = _darrayResize(array);
    }

    u64 addr = (u64)array;

    if (index != length - 1)
    {
        memcpy((void *)(addr + ((index + 1) * stride)), (void *)(addr + (index * stride)), stride * (length - index));
    }
    memcpy((void *)(addr + (index * stride)), valuePtr, stride);

    _darrayFieldSet(array, DARRAY_LENGTH, length + 1);

    return array;
}

//__________________________________________________
//_______________________1__________________________
//______________________11__________________________
//______________________111_________________________
//_____________________11111________________________
//_____________________11111____1___________________
//____________________1111111__11___________________
//____________________1111111__111__________________
//________________1__1111111111111__________________
//________________1111111111111111__________________
//________________11111111111111111_________________
//________________11111111111111111_________________
//_______________111111¶¶1111¶¶1111_________________
//_______________111111¶¶¶_¶¶¶11111_________________
//__________111__111111¶¶¶¶¶¶¶11111__11_____________
//___________1111111111¶¶¶¶¶¶¶_1111_111_____________
//___________111111111¶¶¶¶¶¶¶1¶11111111_____________
//___________111111111¶¶¶¶¶¶¶¶¶1111111______________
//____________1111¶¶11¶¶1¶¶¶¶¶¶1111111______________
//____________1111¶¶¶¶¶¶1¶¶¶¶¶11111111______________
//____________1111¶¶¶¶¶¶1¶¶¶¶¶1111111_______________
//_____________1111¶¶¶¶¶¶¶¶¶¶1111111________________
//_______________111¶¶¶¶¶¶¶1111111_¶¶¶¶¶¶___________
//_______1¶¶¶¶¶¶¶_1111¶¶11111111_1¶¶¶¶¶¶¶¶¶¶¶¶¶11___
// 11¶¶¶¶¶¶¶¶¶¶¶¶¶¶111____1111111¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶
// ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶___¶¶¶1¶¶1____11¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶
// ¶¶¶¶¶¶¶¶¶¶¶_______¶¶¶¶¶¶¶¶__________1¶¶¶¶¶¶¶¶¶¶¶¶¶
// ¶¶¶¶¶¶1___________¶¶¶¶¶¶¶________________¶¶¶¶¶¶¶¶1
// ¶¶¶_____________1¶¶¶¶¶¶¶¶____________________¶¶¶1_
//_______________¶¶¶¶¶¶¶¶¶__________________________
//______________¶¶¶¶¶¶¶¶¶¶__________________________
//

int main()
{
}

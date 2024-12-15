#include "../../defines.h"
#include <stdio.h>

i32 main(void)
{
    i32  size = 1001;
    i32 *array = darray_reserve(size, size);

    FILE *file = fopen("input.txt", "r");

    if (!file)
    {
        printf("error opening file\n");
        return -1;
    }

    char buffer[256] = {};
    i32  i = 0;
    i32  num = 1;
    i32 *ptr = NULL;

    while (fgets(buffer, sizeof(buffer), file))
    {
        ptr = darray_create(size);
        array[i++] = *ptr;

        i32 right = 0;
        num = 0;
        while (right < 256 && buffer[right] != '\0')
        {
            while (buffer[right] != ' ' && buffer[right] != '\0')
            {
                num *= 10;
                num += buffer[right++] - '0';
            }
            printf("%d ", num);
            darray_push(ptr, num);
            num = 0;
            right++;
        }
        printf("\n");

        // int length = darray_length(ptr);
        // for (int j = 0; j < length; j++)
        //{
        //     printf("%d ", ptr[j]);
        // }
        // printf("\n");
        memset(buffer, 0, 256);
    }
}

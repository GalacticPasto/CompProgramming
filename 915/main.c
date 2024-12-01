#include <stdio.h>

#define printArray(nums, numsSize)                                                                                     \
    {                                                                                                                  \
        int i = 0;                                                                                                     \
        for (; i < numsSize; i++)                                                                                      \
        {                                                                                                              \
            printf("%i ", nums[i]);                                                                                    \
        }                                                                                                              \
        printf("\n");                                                                                                  \
    }                                                                                                                  \


int partitionDisjoint(int *nums, int numsSize)
{
    int leftMax[numsSize];
    int rightMin[numsSize];

    leftMax[0] = nums[0];
    rightMin[numsSize - 1] = nums[numsSize - 1];

    for (int i = 1; i < numsSize; i++)
    {
        leftMax[i] = nums[i] > leftMax[i - 1] ? nums[i] : leftMax[i - 1];
    }

    for (int i = numsSize - 2; i >= 0; i--)
    {
        rightMin[i] = nums[i] < rightMin[i + 1] ? nums[i] : rightMin[i + 1];
    }

    printArray(leftMax, numsSize);
    printArray(rightMin, numsSize);

    for (int i = 0; i < numsSize; i++)
    {
        if (leftMax[i] <= rightMin[i + 1])
        {
            return i + 1;
        }
    }

    return -1;
}
int main()
{
    int nums[] = {5, 0, 3, 8, 6};
    int ans = partitionDisjoint(nums, 5);
    printf("%i\n", ans);
}

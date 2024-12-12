#include <stdio.h>

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

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

long long maxStrength(int *nums, int numsSize)
{
    long long max = 1;
    quickSort(nums, 0, numsSize - 1);
    if (numsSize == 1)
    {
        return nums[0];
    }
    else if (nums[0] == 0 && nums[numsSize - 1] == 0)
    {
        return 0;
    }
    else if (numsSize > 1 && nums[1] == 0 && nums[numsSize - 1] == 0)
    {
        return 0;
    }

    for (int i = numsSize - 1; i >= 0 && nums[i] > 0; i--)
    {
        max *= nums[i];
    }

    for (int i = 0; i < numsSize - 1 && nums[i] < 0 && nums[i + 1] < 0; i += 2)
    {
        max *= nums[i];
        max *= nums[i + 1];
    }
    return max;
}

int main()
{
    long long ans = maxStrength((int[]){1, 2, 3, 4, 5, 6, 7, 8, 9, -9, -9}, 11);
    printf("%lli\n", ans);
}
